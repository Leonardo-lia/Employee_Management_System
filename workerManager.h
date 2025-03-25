#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();
	//��ʾ�˵�
	void Show_Menu();
	//�˳��������
	void ExitSystem();
	//���ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//ͳ���ļ�������
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾְ��
	void Show_Emp();
	//ɾ��ְ��
	void Del_Emp();
	//�ж�ְ���Ƿ����
	int IsExist(int id);
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//����
	void Sort_Emp();
	//����ļ�
	void Clean_File();

	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ�룬����ҵ�ָ�뱣����һ�������У��ﵽ����ͬ�����Ա������һ�������Ч��
	Worker** m_EmpArray;//ָ�� Worker* ��ָ�룬ֻҪΪ���������ڴ棨����ͨ�� new������Ҳ����������һ��ʹ����������
	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;

	~WorkerManager();
};
