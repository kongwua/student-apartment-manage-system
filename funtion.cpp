#include "funtion.h"



int check()//�������ע�����Ա�˺�
{

	FILE* fp=NULL;//�ļ�ָ��
	fp = fopen("Adm.dat", "rb+");
	char first;
	first = fgetc(fp);
	if (first == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



void creataccount()//��������Ա�˺�
{
	Adm guanli;
	FILE* fp;//�ļ�ָ��
	fp = fopen("Adm.dat", "rb+");
	char a[20], b[20];
	printf("\t\t���������Ա�˺ţ� ");
	scanf("%s", a);
	printf("\t\t���������Ա���룺 ");
	scanf("%s", b);
	strcpy(guanli.adm_ZH, a);
	strcpy(guanli.adm_Pass, b);//�����˺����뵽�ļ���
	fwrite(&guanli, sizeof(Adm), 1, fp);
	fclose(fp);
	printf("\n\t\tע���˺ųɹ���  ");
	Sleep(1000);//��ʱ1s�ر�
	return;
}



void menu()//�˵�ģ��
{
	int option = 0;
	printf("\n\t\t\t------------------------------\n\t\t\t��ӭʹ��ѧ����Ԣ����ϵͳ\n\t\t\t------------------------------\n");
	system("color 1F");//���������ɫ����
	while (now)
	{
		system("cls");//ÿ��ѭ����ʼʱˢ����Ļ
		do
		{
			system("cls");
			printf("\n                 -----------------------�˵�--------------------\n");
			printf("\t\t|\t          �ٵ�¼                        |\n");
			printf("\t\t|\t          ��ע��                        |\n");
			printf("\t\t|\t          ���޸�����                    |\n");
			printf("\t\t|\t          �ܹ���Ա��¼                  |\n");
			printf("\t\t|\t          ���˳�ϵͳ                    |\n");
			printf("\n                 -----------------------------------------------\n");
			printf("\n");
			printf("\t\t������ѡ��:  [\t ]\b\b\b\b");
			scanf("%d", &option);//��option���и�ֵ
		} while (option > 5|| option < 1);//����ģ��ѡ��Ϊ1111
		tran(option);//��ת
	}
		
}




void tran(int math)//��ת
{
	switch(math)
	{
		case 1:
			login();//��¼
			break;
		case 2:
			regist();//ע��
			break;
		case 3:
			changepass();//����
			break;
		case 4:
			administor();//����Ա��¼
			break;
		case 5:
			printf("���˳�ϵͳ\n��ӭ�´�ʹ��!!!");
			now = 0;
			exit(0);
	}
}




void regist()//ע��ģ��
{
	system("cls");//����
	char c[20];
	Ac a, b;//�����û���Ԫ����
	FILE* fp;
	printf("\n\t\tע�����\n");
	Sleep(500);//��ʱ0.5s
	fp = fopen("Users.dat", "rb+");
	fread(&b, sizeof(Ac), 1, fp);
	printf("\n\t\t�������˺�:[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s", &a.ZH);
	while (1)//����Ƿ��Ѵ����˺�
	{
		if (strcmp(a.ZH, b.ZH))//�ļ�������ͬ�˺�
		{
			if (!feof(fp))//�ļ�δ����ʱ
			{
				fread(&b, sizeof(Ac), 1, fp);
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("���˺��Ѵ��� ! ! !");
			Sleep(1000);
			fclose(fp);
			return;
		}
	}
	int time = 3;//��¼��������Ĵ�����timeΪ0ʱ�˳�����
	do
	{
		system("cls");
		printf("\t\t����������: [ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
		for (i = 0; i < 20; i++)//��ȡ����
		{
			a.Pass[i] = _getch();//����ʾ����
			if (a.Pass[i] == '\r')//������س�,ֹͣ����
			{
				break;
			}
			else if (a.Pass[i] == '\b' && i > 0)
			{
				i -= 2;
				printf("\b \b");//����ɾ��ʱ
			}
			else
			{
				printf("*");//��������
			}
		}
		a.Pass[i] = '\0';
		printf("\n");
		printf("\t\t��ȷ������: [ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
		for (i = 0; i < 20; i++)
		{
			c[i] = _getch();//��������ȷ�ϵ�����
			if (c[i] == '\r')
			{
				break;
			}
			else if (c[i] == '\b' && i > 0)
			{
				i -= 2;
				printf("\b \b");//����ɾ��ʱ
			}
			else
			{
				printf("*");
			}
		}
		c[i] = '\0';
		printf("\n");
		fclose(fp);
		if (!strcmp(a.Pass, c))//���������ȷ
		{
			FILE *fw = fopen("Users.dat", "ab+");//�����ļ�ָ�������洢����
			fwrite(&a, sizeof(Ac), 1, fw);//������д���ļ�
			fclose(fw);
			printf("\n%s,ע��ɹ�! ! !",a.ZH);
			Sleep(1000);
			return;
		}
		else//����������벻ͬ
		{
			if (time != 0)
			{
				printf("\n\n\t\t�������!\n\n\t\t�������������� ! !\n\n\t\t������%d�λ���! ! !\n", time);
				time--;
				system("pause");
				continue;
			}
			else
			{
				printf("\n\t\t����������,�����˳�! \n");
				fclose(fp);
				Sleep(1500);
				return;
			}

		}

	} while (time >= 0);
}




void login()//��¼ģ��
{
	system("cls");//����
	Ac a, b;//���������û��ṹ�����
	printf("\n��¼����\n");
	printf("�˺� �� ");
	scanf("%s", &b.ZH);
	printf("\n���룺 ");
	i = 0;
	for (i = 0; i < 20; i++)//��������
	{
		b.Pass[i] = _getch();//����ʾ����
		if (b.Pass[i] == '\r')
		{
			break;
		}
	    else if (b.Pass[i] == '\b' && i > 0)
		{
			i-=2;
			printf("\b \b");//����ɾ��ʱ
		}
		else
		{
			printf("*");
		}
	}
	b.Pass[i] = '\0';
	printf("\n");
	FILE* fp = fopen("Users.dat", "rb+");//�����ļ�ָ�����Ի���û���Ϣ
	fread(&a, sizeof(Ac), 1, fp);
	while (1)
	{
		if (strcmp(b.ZH, a.ZH) == 0)//����ļ����Ƿ��Ѿ��и��˺�
		{
			break;
		}
		else
		{
			if (!feof(fp))//���ļ�δ����
			{
				fread(&a, sizeof(Ac), 1, fp);//������ȡ
			}
			else
			{
				printf("�˺Ŵ�����˺Ų����ڣ�����");
				Sleep(1000);
				fclose(fp);
				return;
			}
		}
	}
	fclose(fp);
 	if (strcmp(b.Pass, a.Pass) == 0)//��������ȷ
	{
		printf("%s,��ӭ��¼������", a.ZH);
		Sleep(1000);
		system("cls");
		studentlook();
		return;
	}
	else
	{
		printf("������󣡣���\n");
		Sleep(1000);
		system("cls");
		return;
	}
}


//ѧ���˲鿴���ലλ��Ϣ
void studentlook()
{
	printf("\t\t----------ѧ����---------\n");
	SearchFreebed();
}


void changepass()//��������ģ��
{
	system("cls");
	Ac a, b;
	printf("���ܽ���!!!\n");
	printf("�������˺ţ�");
	scanf("%s", &b.ZH);
	printf("\n���������룺");
	for (i = 0; i < 20; i++)
	{
		b.Pass[i] = _getch();//��������
		if (b.Pass[i] == '\r')
		{
			break;
		}
		else if (b.Pass[i] == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");//����ɾ��ʱ
		}
		else
		{
			printf("*");
		}
	}
	b.Pass[i] = 0;
	printf("\n");
	FILE* fp = fopen("Users.dat", "rb+");//��ȡ�û���Ϣ
	if (fp == NULL) return;
	fread(&a, sizeof(Ac), 1, fp);
	while (1)
	{
		if (strcmp(b.ZH, a.ZH) == 0)//����ļ����Ƿ��Ѿ��и��˺�
		{
			break;
		}
		else
		{
			if (!feof(fp))//���ļ�δ����
			{
				fread(&a, sizeof(Ac), 1, fp);//������ȡ
			}
			else
			{
				printf("�˺Ŵ�����˺Ų����ڣ�����");
				Sleep(1000);
				fclose(fp);
				return;
			}
		}
	}
	if (strcmp(b.Pass, a.Pass) == 0)
	{
		printf("%s,������ȷ������\n",a.ZH);
		char c[20], d[20];
		int time = 3;//��¼����ȷ���������
		do
		{
			printf("\t\t�����������룺[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
			for (i = 0; i < 20; i++)
			{
				c[i] = _getch();//��������
				if (c[i] == '\r')
				{
					break;
				}
				else if (c[i] == '\b' && i > 0)
				{
					i -= 2;
					printf("\b \b");//����ɾ��ʱ
				}
				else
				{
					printf("*");
				}
			}
			c[i] = '\0';
			printf("\n");
			printf("\t\t��ȷ�����룺[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
			for (i = 0; i < 20; i++)
			{
				d[i] = _getch();//��������
				if (d[i] == '\r')
				{
					break;
				}
				else if (d[i] == '\b' && i > 0)
				{
					i -= 2;
					printf("\b \b");//����ɾ��ʱ
				}
				else
				{
					printf("*");
				}
			}
			d[i] = '\0';
			printf("\n");

			if (!strcmp(d, c))//�����������������
			{
				strcpy(a.Pass, c);
				fseek(fp, -((int)(sizeof(Ac) - 40)), SEEK_CUR);//���ļ�ָ�����Ҫ�޸ĵ������λ��
				fprintf(fp, "%s", a.Pass);
				Sleep(500);
				fclose(fp);
				printf("\t\t���ĳɹ�!!");
				Sleep(1000);
				return;
			}
			else
			{
				if (time != 0)
				{
					printf("�������\n\n�������������룡��\n\n������%d�λ��ᣡ����", time);
					system("pause");
					system("cls");//����
					time--;
					continue;
				}
				else
				{
					printf("\n\t\t���������󣬼����˳�!");
					fclose(fp);
					Sleep(1000);
					return;
				}
			}
		} while (time >= 0);
	}
	else
	{
		printf("\n������󣡣���\n");
		Sleep(1000);
		system("cls");
		return;
	}
}


