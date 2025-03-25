#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
	WorkerManager wm;

	int choice = 0;

	while (true)
	{
		wm.Show_Menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出管理程序
			wm.ExitSystem();
			break;
		case 1://增加职工信息
			wm.Add_Emp();
			break;
		case 2://显示职工信息
			wm.Show_Emp();
			break;
		case 3://删除职工信息
			wm.Del_Emp();
			break;
		case 4://修改职工信息
			wm.Mod_Emp();
			break;
		case 5://查找职工信息
			wm.Find_Emp();
			break;
		case 6://按照编号排序
			wm.Sort_Emp();
			break;
		case 7://清空所有文档
			wm.Clean_File();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}

	////测试代码，多态，一个接口有多种形态，由于创建对象的不同而不同
	//Worker* worker1 = NULL;//NULL的意思是无内容，但是已经分配了地址和空间
	//worker1 = new Employee(1, "张三", 1);
	//worker1->showInfo();
	//Worker* worker2 = NULL;//NULL的意思是无内容，但是已经分配了地址和空间
	//worker2 = new Manager(2, "李四", 2);
	//worker2->showInfo();
	//Worker* worker3 = NULL;//NULL的意思是无内容，但是已经分配了地址和空间
	//worker3 = new Boss(3, "王五", 3);
	//worker3->showInfo();

	//Worker* worker = NULL;//NULL的意思是0，没有指向任何有效的内存地址
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;//删除一个指针之后，编译器只会释放该指针所指向的内存空间，而不会删除这个指针本身
	//worker = NULL;
	//worker = new Manager(2, "李四", 2);
	//worker->showInfo();
	//delete worker;
	//worker = NULL;
	//worker = new Boss(3, "王五", 3);
	//worker->showInfo();
	//delete worker;

	system("pause");
	return 0;
}