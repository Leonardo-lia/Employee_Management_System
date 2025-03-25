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
	//显示菜单
	void Show_Menu();
	//退出管理程序
	void ExitSystem();
	//添加职工
	void Add_Emp();
	//保存文件
	void save();
	//统计文件中人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//显示职工
	void Show_Emp();
	//删除职工
	void Del_Emp();
	//判断职工是否存在
	int IsExist(int id);
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//排序
	void Sort_Emp();
	//清空文件
	void Clean_File();

	//记录职工人数
	int m_EmpNum;
	//职工数组指针，将大家的指针保存在一个数组中，达到将不同种类的员工放在一个数组的效果
	Worker** m_EmpArray;//指向 Worker* 的指针，只要为它分配了内存（例如通过 new），它也可以像数组一样使用索引操作
	//判断文件是否为空的标志
	bool m_FileIsEmpty;

	~WorkerManager();
};
