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
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳��������
			wm.ExitSystem();
			break;
		case 1://����ְ����Ϣ
			wm.Add_Emp();
			break;
		case 2://��ʾְ����Ϣ
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ����Ϣ
			wm.Del_Emp();
			break;
		case 4://�޸�ְ����Ϣ
			wm.Mod_Emp();
			break;
		case 5://����ְ����Ϣ
			wm.Find_Emp();
			break;
		case 6://���ձ������
			wm.Sort_Emp();
			break;
		case 7://��������ĵ�
			wm.Clean_File();
			break;
		default:
			system("cls");//����
			break;
		}
	}

	////���Դ��룬��̬��һ���ӿ��ж�����̬�����ڴ�������Ĳ�ͬ����ͬ
	//Worker* worker1 = NULL;//NULL����˼�������ݣ������Ѿ������˵�ַ�Ϳռ�
	//worker1 = new Employee(1, "����", 1);
	//worker1->showInfo();
	//Worker* worker2 = NULL;//NULL����˼�������ݣ������Ѿ������˵�ַ�Ϳռ�
	//worker2 = new Manager(2, "����", 2);
	//worker2->showInfo();
	//Worker* worker3 = NULL;//NULL����˼�������ݣ������Ѿ������˵�ַ�Ϳռ�
	//worker3 = new Boss(3, "����", 3);
	//worker3->showInfo();

	//Worker* worker = NULL;//NULL����˼��0��û��ָ���κ���Ч���ڴ��ַ
	//worker = new Employee(1, "����", 1);
	//worker->showInfo();
	//delete worker;//ɾ��һ��ָ��֮�󣬱�����ֻ���ͷŸ�ָ����ָ����ڴ�ռ䣬������ɾ�����ָ�뱾��
	//worker = NULL;
	//worker = new Manager(2, "����", 2);
	//worker->showInfo();
	//delete worker;
	//worker = NULL;
	//worker = new Boss(3, "����", 3);
	//worker->showInfo();
	//delete worker;

	system("pause");
	return 0;
}