#include"funtion.h"

//����ģ��˵�
void searchmenu()
{
	int option = 0;
	printf("\n\t\t\t------------------------------\n\t\t��ӭʹ�ò�ѯϵͳ\n\t\t------------------------------");
	system("color 1F");//���������ɫ
	while (now)
	{
		system("cls");
		do
		{
			system("cls");
			printf("\n                 ------------------��ѯ�˵�-------------------\n");
			printf("\t\t|\t                                      |\n");
			printf("\t\t|\t        �ٲ�ѯ�п��ലλ������        |\n");
			printf("\t\t|\t        �ڲ�ѯѧԺ��λ���            |\n");
			printf("\t\t|\t        �۲�ѯ��Ԣ��λ���            |\n");
			printf("\t\t|\t        ��ͳ�ƿմ����                |\n");
			printf("\t\t|\t        ���˳�                        |\n");
			printf("\n                 ---------------------------------------------\n");
			printf("\n");
			printf("\t\t������ѡ��:  [\t ]\b\b\b\b");
			scanf("%d", &option);//��option���и�ֵ
		} while (option > 5 || option < 1);//��ѡ���ڽ綨��Χʱ������ѭ��
		searchtran(option);
	}
}


//��ѯ��תģ��
void searchtran(int math)
{
	switch (math)
	{
	case 1:
		SearchFreebed();//��ѯ�п��ലλ������
		searchmenu();
		break;
	case 2:
		schoolbed();//��ѯѧԺ��λ���
		searchmenu();//��ѯģ��
		break;
	case 3:
		SearchRidge();//��ѯ��Ԣ��λ���
		searchmenu();
		break;
	case 4:
		CountFreebed();//ͳ�ƿմ�
		searchmenu();
		break;
	case 5:
		admmenu();//�ص����˵�
		exit(0);//�˳�
	}
}



/*�������ܣ���ѯ�п��ലλ������
* ˼·����ȡ�ļ����ݣ����п��ലλ�����ӡ����
*/
void SearchFreebed ()
{
	int num = 0;//num��������
	STU* head = file_read();//��ȡ�ļ����ݣ�������������
	STU* p =head;//p������������
	if (p == NULL)
	{
		printf("��ȡ�ļ�ʧ�ܣ�����\n");
	}
	system("cls");
	printf("\t\t�����ലλ�������У�\n");
	printf("\t\t���\t������\t¥��\t�����\t�������\t��λ\t�ѷ��䴲λ\t���ലλ\tѧԺ\n");
	while (p != NULL)
	{
		if (p->data.freebed > 0)//���п��ലλ�����ӡ����
		{
			num++;
			printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n",num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
		}
		p = p->next;
	}
	printf("\n\n\t\t�������������һ���˵���");
	getchar();
	getchar();
}






/*��ѯѧԺ��λ���
*/
void schoolbed()
{
	char s[30];//��¼�����ѧԺ����
	int n;//n��¼ѡ��
	STU* p = file_read();//��ȡ�ļ����ݣ�������������
	if (p == NULL)
	{
		printf("�ļ��򿪴���");
		Sleep(1000);
		return;
	}
	system("cls");
	printf("\t\t������Ҫ��ѯ��ѧԺ���ƣ�\n");
	printf("\t\t���磺jsj�������ѧԺ�� zdh���Զ���ѧԺ��\n\t\t");
	getchar();//���ջس�
	scanf("%s",s);//��ȡҪ��ѯ��ѧԺ����
	system("cls");
	do{
		system("cls");
		printf("\t\t��ѡ��Ҫ��ѯ�����ͣ�\n\n");
		printf("\t\t��ȫѧԺ\t\t������\t\t��Ů��\n\n");
		printf("\t\t������ѡ��:  [\t ]\b\b\b\b");
		scanf("%d", &n);
		if (n < 1 || n > 3)
		{
			printf("\t\t������������������");
			Sleep(1000);
		}
	} while (n < 1 || n > 3);
	switch (n)
	{
	case 1:
		all(p,s);//��ӡȫѧԺס����Ϣ
		break;
    case 2:
		man(p,s);//��ӡѧԺ������Ϣ
		break;
	case 3:
		women(p,s);//��ӡѧԺŮ����Ϣ
		break;

	}

}

void all(STU* p,char s[30])//��ӡȫѧԺס����Ϣ
{
	int num = 0;//num��������
	int flag = 0;//��flagΪ1���ʾ��ѯ�����
	system("cls");
	printf("\t\tȫѧԺ��ס�������\n");
	printf("\t\t���\t������\t¥��\t�����\t�������\t��λ\t�ѷ��䴲λ\t���ലλ\tѧԺ\n");
	while (p != NULL)
	{
		if (strcmp(s,p->data.school)==0)//������ѡѧԺ�����ӡ����
		{
			num++;
			printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)//��û�в�ѯ��
	{
		system("cls");
		printf("\t\t�޲�ѯ�����\n");
	}
	printf("\n\n\t\t�������������һ���˵���");
	getchar();
	getchar();
}


void man(STU* p, char s[30])//��ӡȫѧԺ����ס����Ϣ
{
	int num = 0;//num��������
	int flag = 0;//��flagΪ1���ʾ��ѯ�����
	system("cls");
	printf("\t\tȫѧԺ������ס�������\n");
	printf("\t\t���\t������\t¥��\t�����\t�������\t��λ\t�ѷ��䴲λ\t���ലλ\tѧԺ\n");
	while (p != NULL)
	{
		if (strcmp(s, p->data.school) == 0 && strcmp("m",p->data.roomtype)==0)//������ѡѧԺ���������ᣬ���ӡ����
		{
			num++;
			printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)//��û�в�ѯ��
	{
		system("cls");
		printf("\t\t�޲�ѯ�����\n");
	}
	printf("\n\n\t\t�������������һ���˵���");
	getchar();
	getchar();
}



void women(STU* p, char s[30])//��ӡȫѧԺŮ��ס����Ϣ
{
	int num = 0;//num��������
	int flag = 0;//��flagΪ1���ʾ��ѯ�����
	system("cls");
	printf("\t\tȫѧԺŮ����ס�������\n");
	printf("\t\t���\t������\t¥��\t�����\t�������\t��λ\t�ѷ��䴲λ\t���ലλ\tѧԺ\n");
	while (p != NULL)
	{
		if (strcmp(s, p->data.school) == 0 && strcmp("w", p->data.roomtype) == 0)//������ѡѧԺ���������ᣬ���ӡ����
		{
			num++;
			printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)//��û�в�ѯ��
	{
		system("cls");
		printf("\t\t�޲�ѯ�����\n");
	}
	printf("\n\n\t\t�������������һ���˵���");
	getchar();
	getchar();
}




/*��Ԣס�������ѯ
* ���룺����������ʼ������ĩβ����
* ���������ѯ��ס�����
*/
void SearchRidge()
{
	int option;
	system("cls");
	do
	{
		printf("\t\t--------��Ԣס�������ѯ---------\n");
		printf("\n\t\t��ѡ���ѯ���ͣ� ��ȫ����Ԣ��ѯ   ���Զ��巶Χ��ѯ   �۵����ѯ\n");
		printf("\t\t������ѡ��:  [\t ]\b\b\b\b");
		scanf("%d", &option);
		if (option < 1 || option>3)
		{
			printf("\t\t�����������������룡����\n");
			Sleep(1000);
			system("cls");
		}
	} while (option < 1 || option>3);
	switch (option)
	{
	case 1:
		SearchRidgeAll();//�鿴������������ס����Ϣ
		break;
	case 2:
		SearchRidgeSome();//�鿴�Զ��巶Χ������Ϣ
		break;
	case 3:
		SearchOne();//�鿴��������
		break;
	}
	
}


void SearchRidgeAll()//�鿴������������ס����Ϣ
{
	int num = 0;//num��������
	int flag = 0;//��flagΪ1���ʾ��ѯ�����
	system("cls");
	STU* p = file_read();
	printf("\t\t��������ס�������\n");
	printf("\t\t���\t������\t¥��\t�����\t�������\t��λ\t�ѷ��䴲λ\t���ലλ\tѧԺ\n");
	while (p != NULL)
	{
			num++;
			printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
			flag = 1;
		p = p->next;
	}
	if (flag == 0)//��û�в�ѯ��
	{
		system("cls");
		printf("\t\t�޲�ѯ�����\n");
	}
	printf("\n\n\t\t�������������һ���˵���");
	getchar();
	getchar();
}



void SearchRidgeSome()//�鿴�Զ��巶Χ������Ϣ
{
	int num = 0;//num��������
	int flag = 0;//��flagΪ1���ʾ��ѯ�����
	STU* p = file_read();//��ȡ�ļ�
	system("cls");
	char s[20];//��¼��Ҫ��ѯ��������
	int start = 0, end = 0;//��¼Ҫ��ѯ�Ķ���

	do
	{
		printf("\t\t������Ҫ��ѯ��������:\n\t\t");
		printf("��: d(��������x��������\n\t\t");
		scanf("%s", s);
		if (strcmp(s, "d") != 0 && strcmp(s, "x") != 0)//������벻�淶
		{
			printf("\n\n\t\t���벻�淶�����������룡����\n");
			Sleep(1000);
			system("cls");
		}
	} while (strcmp(s, "d") != 0 && strcmp(s, "x") != 0);

	do
	{
		printf("\t\t������Ҫ��ѯ�Ķ���\n");
		printf("\n\t\t(��Ҫ��ѯ��Ƭ���������������0)\n");
		printf("\n\t\t�����뿪ʼ������");
		scanf("%d", &start);
		printf("\n\t\t�������������");
		scanf("%d", &end);
		if (start > end || start < 0 || end < 0)//�����벻�淶
		{
			printf("\n\t\t�����������������룡����\n");
			Sleep(1000);
			system("cls");
		}
	} while (start > end || start < 0 || end < 0);

	if (start == 0 && end == 0)//���������0
	{
		system("cls");
		printf("\t\t��ѡ�����ס�������\n");
		printf("\t\t���\t������\t¥��\t�����\t�������\t��λ\t�ѷ��䴲λ\t���ലλ\tѧԺ\n");
		while (p != NULL)
		{
			if (strcmp(s, p->data.area) == 0)//�����������������ӡ
			{
				num++;
				printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0)//��û�в�ѯ��
		{
			system("cls");
			printf("\t\t�޲�ѯ�����\n");
		}
		printf("\n\n\t\t�������������һ���˵���");
		getchar();
		getchar();
	}
	else
	{
		system("cls");
		printf("\t\t��ѡ�����ס�������\n");
		printf("\t\t���\t������\t¥��\t�����\t�������\t��λ\t�ѷ��䴲λ\t���ലλ\tѧԺ\n");
		while (p != NULL)
		{
			if (strcmp(s, p->data.area) == 0 && p->data.ridge >= start && p->data.ridge <= end)//�����������������ӡ
			{
				num++;
				printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0)//��û�в�ѯ��
		{
			system("cls");
			printf("\t\t�޲�ѯ�����\n");
		}
		printf("\n\n\t\t�������������һ���˵���");
		getchar();
		getchar();
	}
}




/*�������ã��鿴����������Ϣ
* ���룺�������������������
* ���:ס����Ϣ
* ���أ����ҵ�������1�����򷵻�0
*/
int SearchOne()
{
	char s[20];//��¼Ҫ���������
	int a, b;//a��������b�������
	int flag = 0;//��־�Ƿ���ҵ�
	STU* p = file_read();
	system("cls");
	do
	{
		printf("\t\t��������������d(��)/x(��)    ");
		scanf("%s", s);
		printf("\t\t�����붰����");
		scanf("%d", &a);
		printf("\t\t�����뷿��ţ�");
		scanf("%d", &b);
		if ((strcmp(s, "d") && strcmp(s, "x")) || a < 0 || b < 0)
		{
			printf("\n\t\t�����������������룡����");
			Sleep(1000);
			system("cls");
		}
	} while ((strcmp(s, "d") && strcmp(s, "x")) || a < 0 || b < 0);

	printf("\t\t����ѯ����ϢΪ��\n");
	while (p != NULL)
	{
		if (strcmp(s, p->data.area) == 0 && a == p->data.ridge && b == p->data.room)
		{
			printf("\t\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		system("cls");
		printf("\t\tδ�ҵ�������ᣡ\n");
	}
	getchar();
	getchar();
	return flag;
}





/*�������ã�ͳ�ƿմ�
* ���룺����
*/
void CountFreebed()
{
	int option;
	system("cls");
	do
	{
		printf("\t\t-------�մ�λͳ�Ʋ�ѯ����------\n");
		printf("\n\t\t��ѯ���\t�ٹ�Ԣ����ѯ \t��ѧԺ����ѯ\n");
		printf("\t\t������ѡ��:  [\t ]\b\b\b\b");
		scanf("%d", &option);
		if (option < 1 || option>2)
		{
			printf("\nѡ�������������������룡����\n");
			Sleep(1000);
			system("cls");
		}
	} while (option < 1 || option>2);

	switch (option)
	{
	case 1:
		Countdiy();//�Զ����������ͳ��
		break;
	case 2:
		Countschool();//ѧԺ�մ���ѯ
		break;
	}
}


//�Զ�������մ�ͳ��
void Countdiy()
{
	int sum = 0;//sum��¼���������ܿմ���
	int sum1 = 0;//sum1��¼����ѯ����մ���
	int a[50] = { 0 };//a�����¼����Ӧ�����Ŀմ�λ��
	STU* p = file_read();//��ȡ�ļ�
	system("cls");
	char s[20];//��¼��Ҫ��ѯ��������
	int start = 0, end = 0;//��¼Ҫ��ѯ�Ķ���

	do
	{
		printf("\t\t������Ҫͳ�Ƶ�������:\n\t\t");
		printf("��: d(��������x��������\n\t\t");
		scanf("%s", s);
		if (strcmp(s, "d") != 0 && strcmp(s, "x") != 0)//������벻�淶
		{
			printf("\n\n\t\t���벻�淶�����������룡����\n");
			Sleep(1000);
			system("cls");
		}
	} while (strcmp(s, "d") != 0 && strcmp(s, "x") != 0);

	do
	{
		printf("\t\t������Ҫͳ�ƵĶ���\n");
		printf("\n\t\t(��Ҫͳ����Ƭ���������������0)\n");
		printf("\n\t\t�����뿪ʼ������");
		scanf("%d", &start);
		printf("\n\t\t�������������: ");
		scanf("%d", &end);
		if (start > end || start < 0 || end < 0)//�����벻�淶
		{
			printf("\n\t\t�����������������룡����\n");
			Sleep(1000);
			system("cls");
		}
	} while (start > end || start < 0 || end < 0);

	if (start == 0 && end == 0)//���������0
	{
		system("cls");
		printf("\t\t%s���Ŀմ������\n",s);
		while (p != NULL)
		{
			if (strcmp(s, p->data.area) == 0 && p->data.freebed > 0)//���������������пմ�
			{
				sum1++;

			}
			if (p->data.freebed > 0)//ͳ�����пմ�
			{
				sum++;
			}
			p = p->next;
		}
		printf("\t\t���������ܿմ�: %d\n", sum);
		printf("\t\t%s�����ܿմ���Ϊ�� %d\n",s, sum1);
		printf("\n\n\t\t�������������һ���˵���");
		getchar();
		getchar();
	}
	else
	{
		system("cls");
		printf("\t\t��ѡ����Ŀմ������\n");
		while (p != NULL)
		{
			if (p->data.freebed > 0) sum++;//���пմ���sum++
			if (strcmp(s, p->data.area) == 0 && p->data.ridge >= start && p->data.ridge <= end)
			{
				if (p->data.freebed > 0)
				{
					a[p->data.ridge]++;
					sum1++;
    			}
			}
			p = p->next;
		}
		printf("\t\t���������ܿմ�: %d\n", sum);
		printf("\t\t��ѡ������ܿմ���Ϊ�� %d\n",sum1);
		for (i = 1; i < 50; i++)
		{
			if (a[i] > 0)
			{
				printf("\t\t%s %d �Ŀ��ലλ��%d\n", s, i, a[i]);
			}
		}
		printf("\n\n\t\t�������������һ���˵���");
		getchar();
		getchar();
	}
}

//��ѯѧԺ�մ�
	void Countschool()
{
		char s[30];//��¼�����ѧԺ����
		int sum = 0, sum1 = 0, sum2 = 0;//sum��¼ѧԺ�пմ�����sum1��¼�����մ�����sum2��¼Ů���մ���
		STU* p = file_read();//��ȡ�ļ����ݣ�������������
		if (p == NULL)
		{
			printf("�ļ��򿪴���");
			Sleep(1000);
			return;
		}
		system("cls");
		printf("\t\t������Ҫ��ѯ��ѧԺ���ƣ�\n");
		printf("\t\t���磺jsj�������ѧԺ�� zdh���Զ���ѧԺ��\n\t\t");
		getchar();//���ջس�
		scanf("%s", s);//��ȡҪ��ѯ��ѧԺ����
		system("cls");
		while (p != NULL)
		{
			if (strcmp(s, p->data.school) == 0 && p->data.freebed > 0)//ɸѡѧԺ�մ�
			{
				sum++;
				if (strcmp("m", p->data.roomtype) == 0) sum1++;
				if (strcmp("w", p->data.roomtype) == 0) sum2++;
			}
			p = p->next;
		}
		system("cls");
		printf("\t\t------�մ�ͳ����Ϣ-----\n\n");
		printf("\t\t%sѧԺ���ܿմ�Ϊ��%d\n",s,sum);
		printf("\t\t%sѧԺ����������մ�Ϊ��%d\n", s, sum1);
		printf("\t\t%sѧԺ��Ů������մ�Ϊ��%d\n", s, sum2);
		printf("\n\n\t\t�������������һ���˵���");
		getchar();
		getchar();
}