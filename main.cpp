
//#include"funtion.h"//funtionͷ�ļ�
#include"funtion.h"


int now = 1;//ѭ��ʱʹ��
int i;//�����е�ͨ�ñ���
int main()//������
{
	int flag;
	flag = check();
	if (flag == 1)//�ж��Ƿ��Ѵ�������Ա�˺�
	{
		creataccount();
	}
	menu();//�˵�
	return 0;
}