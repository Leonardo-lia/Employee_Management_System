#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;//退出,不执行后面操作
	}
	//2、文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3、文件存在，数据不为空
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//存数据
	this->init_Emp();
	this->m_FileIsEmpty = false;

	//测试
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号" << this->m_EmpArray[i]->m_Id
			<< "\t姓名" << this->m_EmpArray[i]->m_Name
			<< "\t\t部门编号" << this->m_EmpArray[i]->m_DeptId << endl;
	}
}
//统计库人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)//逐个字段读取数据，并自动跳过分隔符
	{
		//按行统计
		num++;
	}
	return num;
}
//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)//逐行匹配赋值读取
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
//显示菜单
void WorkerManager::Show_Menu()
{
	cout << "*----------------*" << endl;
	cout << "* 0.退出管理程序 *" << endl;
	cout << "* 1.增加职工信息 *" << endl;
	cout << "* 2.显示职工信息 *" << endl;
	cout << "* 3.删除职工信息 *" << endl;
	cout << "* 4.修改职工信息 *" << endl;
	cout << "* 5.查找职工信息 *" << endl;
	cout << "* 6.按照编号排序 *" << endl;
	cout << "* 7.清空所有文档 *" << endl;
	cout << "*----------------*" << endl;
}
//退出管理程序
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
//保存到文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量：" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		//将原来空间下数据拷贝到新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号：" ;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" ;
			cin >> name;
			cout << "请选择该职工岗位：1普通职工，2经理，3老板：";
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更新新空间的指向
		this->m_EmpArray = newSpace;
		//更新职工人数
		this->m_EmpNum = newSize;
		//更新文件为空的标识
		this->m_FileIsEmpty = false;
		cout << "成功添加"<<addNum<<"名新职工" << endl;
		this->save();
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");
}
//显示职工
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
//判断职工是否存在
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按照职工的编号删除
		cout << "请输入想要删除的职工的编号：";
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		cout << index;

		if (index != -1)
		{
			//数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//数据同步更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "未找到该职工" << endl;
		}
	}
	if (this->m_EmpNum == 0)
	{
		this->m_FileIsEmpty = true;
	}
	system("pause");
	system("cls");
}
//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：";
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int newSelect = 0;
			cout << "已查找到" << id << "号职工" << endl;
			cout << "请输入职工编号：";
			cin >> newId;
			cout << "请输入职工姓名：";
			cin >> newName;
			cout << "请选择该职工岗位：1普通职工，2经理，3老板：";
			cin >> newSelect;

			Worker* worker = NULL;
			switch (newSelect)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			//更新数据到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功！" << endl;
			this->save();
		}
		else
		{
			cout << "未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式，1按职工编号，2按职工姓名：";
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入职工编号：";
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入职工姓名：";
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败" << endl;
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式，1升序，2降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功，结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
}
void WorkerManager::Clean_File()
{
	cout << "确定清空？1确定，2返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	else if (select == 2)
	{
		cout << "返回" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}