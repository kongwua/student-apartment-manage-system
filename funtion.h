#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

#ifndef FUNTION_H
#define FUNTION_H
#pragma warning(disable : 4996)//�ر�scanf��������
#define LEN sizeof(STU) //LEN��ʾѧ����Ϣ�ṹ��ĳ���
extern int now;//ʹ��ȫ�ֱ���
extern int i;


typedef struct account//�����û����ݴ洢��Ԫ
{
	char ZH[20];//�˺�
	char Pass[20];//����
}Ac;
typedef struct adm//��������Ա�˺�
{
	char adm_ZH[20];//�˺�
	char adm_Pass[20];//����
}Adm;
typedef struct domitory//ѧ��������Ϣ�ṹ��
{
	char area[5];//��������Ŀǰ�ֶ�������
	int  ridge;//����
	int room;//�����
	char roomtype[5];//������𣬷�Ϊ��Ů�� ��
	int bed;//��λ��
	int rebed;//�ѷ��䴲λ��
	int freebed;//���ലλ����Ҫ����
	char school[20];//ѧԺ
}domitory;
typedef struct student//����ѧ��ס����Ϣ�洢��Ԫ(��̬����
{
	domitory data;//�洢ѧ����Ϣ
	struct student* next;//����βָ����������һ�ṹ��ĵ�ַ
}STU; 






//��¼ϵͳ
int check();//����Ƿ�ע�����Ա�˺�
void creataccount();//��������Ա�˺�
void menu();//�˵�
void tran(int math);//��ת����
void regist();//ע�ắ��
void login();//��¼����
void changepass();//�������뺯��
void administor();//�����¼ģ��
void admmenu();//����˵�
void admtran(int math);//ϵͳ��ת����
void look();//�鿴�û�����
void change();//�޸��û�����
void studentlook();//ѧ���˲鿴�մ���Ϣ





//����Աϵͳ
void save();//¼��ס����Ϣ
STU* create(int k);//������̬��������ѧ����Ϣ
int save_txt(STU* head);//�������е�����¼��room.txt��,�����ļ��е����ݸ���
void sort(int n);//����������room.txt�е����ݽ�������
STU* file_read();//��ȡroom.txt�е����ݣ�����һ����������ͷָ��
STU* check_data(STU* p1, STU* p2);//�Ƚ������������ݣ�����Ƿ����ظ�����

void searchmenu();//��ѯģ��
void searchtran(int math);//��ѯ��תģ��
void SearchFreebed();//��ѯ�п��ലλ������
void schoolbed();//��ѯѧԺ��λ���
void all(STU* p, char s[30]);//��ӡȫѧԺס����Ϣ
void man(STU* p, char s[30]);//����ѧԺ������Ϣ
void women(STU* p, char s[30]);//����ѧԺŮ����Ϣ

void SearchRidge();//��ѯ��Ԣ��λ���
void SearchRidgeAll();//�鿴������������ס����Ϣ
void SearchRidgeSome();//��ѯ�Զ�������ס����Ϣ
int SearchOne();//�鿴��������

void CountFreebed();//ͳ�ƿմ�
void Countdiy();//�Զ�������ͳ��
void Countschool();//ѧԺ�մ�ͳ��


void ChangeIm();//����ģ��
void ChangeStudent();//����ѧ����Ϣ
void delateStudent();//����ɾ��ѧ����Ϣ
STU* delate(char a[20], int b, int c,STU* head);//ɾ���ļ������ݣ�aΪ��������bΪ������cΪ�����,headΪҪɾ��������ͷָ��


void backup();//����ģ��
void backsave1();//�ļ����ƺ��� ��room�ļ������ݸ��Ƶ�backup�ļ���
void backupsave2();//��backup�ļ�������д��room�ļ���

void ChangeZH();//�޸Ĺ���Ա�˺���Ϣ

void ManageStu();//����ѧ���˺�
#endif // !1


