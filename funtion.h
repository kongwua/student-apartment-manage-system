#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

#ifndef FUNTION_H
#define FUNTION_H
#pragma warning(disable : 4996)//关闭scanf函数警报
#define LEN sizeof(STU) //LEN表示学生信息结构体的长度
extern int now;//使用全局变量
extern int i;


typedef struct account//创建用户数据存储单元
{
	char ZH[20];//账号
	char Pass[20];//密码
}Ac;
typedef struct adm//创建管理员账号
{
	char adm_ZH[20];//账号
	char adm_Pass[20];//密码
}Adm;
typedef struct domitory//学生宿舍信息结构体
{
	char area[5];//生活区，目前分东西两区
	int  ridge;//栋数
	int room;//房间号
	char roomtype[5];//房间类别，分为男女两 类
	int bed;//床位数
	int rebed;//已分配床位数
	int freebed;//空余床位，需要计算
	char school[20];//学院
}domitory;
typedef struct student//创建学生住宿信息存储单元(动态链表）
{
	domitory data;//存储学生信息
	struct student* next;//建立尾指针来保存下一结构体的地址
}STU; 






//登录系统
int check();//检查是否注册管理员账号
void creataccount();//创建管理员账号
void menu();//菜单
void tran(int math);//中转函数
void regist();//注册函数
void login();//登录函数
void changepass();//更改密码函数
void administor();//管理登录模块
void admmenu();//管理菜单
void admtran(int math);//系统中转函数
void look();//查看用户函数
void change();//修改用户函数
void studentlook();//学生端查看空床信息





//管理员系统
void save();//录入住宿信息
STU* create(int k);//创建动态链表，输入学生信息
int save_txt(STU* head);//将链表中的数据录入room.txt中,返回文件中的数据个数
void sort(int n);//排序函数，对room.txt中的数据进行排序
STU* file_read();//读取room.txt中的数据，建立一个链表，返回头指针
STU* check_data(STU* p1, STU* p2);//比较两个链表数据，检查是否有重复数据

void searchmenu();//查询模块
void searchtran(int math);//查询中转模块
void SearchFreebed();//查询有空余床位的宿舍
void schoolbed();//查询学院床位情况
void all(STU* p, char s[30]);//打印全学院住宿信息
void man(STU* p, char s[30]);//查找学院男生信息
void women(STU* p, char s[30]);//查找学院女生信息

void SearchRidge();//查询公寓床位情况
void SearchRidgeAll();//查看东西两区所有住宿信息
void SearchRidgeSome();//查询自定义区域住宿信息
int SearchOne();//查看单间宿舍

void CountFreebed();//统计空床
void Countdiy();//自定义区域统计
void Countschool();//学院空床统计


void ChangeIm();//更改模块
void ChangeStudent();//更改学生信息
void delateStudent();//批量删除学生信息
STU* delate(char a[20], int b, int c,STU* head);//删除文件中数据，a为生活区，b为栋数，c为房间号,head为要删除的链表头指针


void backup();//备份模块
void backsave1();//文件复制函数 将room文件的内容复制到backup文件中
void backupsave2();//将backup文件中数据写入room文件中

void ChangeZH();//修改管理员账号信息

void ManageStu();//管理学生账号
#endif // !1


