#include "funtion.h"


//����ѧ���˺�
void ManageStu()
{
	int option;//��¼ѡ��
	system("cls");
	do
	{
		printf("\t\t----------ѧ���˺Ź������----------\n");
		printf("\t\t�ٲ鿴ѧ���˺���Ϣ\t���޸�ѧ���˺���Ϣ\n");
		printf("\t\t������ѡ��:  [\t ]\b\b\b\b");
		scanf("%d", &option);
		if (option < 1 || option>2)
		{
			printf("\t\t������������������\n");
			Sleep(1000); 
			system("cls");
		}
	} while (option < 1 || option>2);
	switch (option)
	{
	 case 1:
		 look();//�鿴ѧ���˺���Ϣ
		 break;
	 case 2:
		 change();//����ѧ���˺���Ϣ
		 break;
	}
}




//�鿴ѧ���˺���Ϣ
void look()
{
	system("cls");
	FILE* fp = fopen("Users.dat","rb+");
	char k=fgetc(fp);
	if (k == EOF)
	{
		printf("�ļ�������Ϣ��");
		Sleep(2000);
		return;
	}
	rewind(fp);
	Ac a;
	fread(&a, sizeof(Ac), 1, fp);
	while (1)
	{
		printf("\t\t�˺ţ�%s\n\t\t���룺%s\n\n", a.ZH, a.Pass);
		if (k!=EOF)
		{
			fread(&a, sizeof(Ac), 1, fp);
			k = fgetc(fp);
			fseek(fp, -1, SEEK_CUR);
		}
		else
		{
			break;
		}
	}
	fclose(fp);
	system("pause");
	return;
}


//����ѧ���˺�
void change()
{
	system("cls");
	Ac a, b;
	int num;
	char s[20];//�����˺�
	FILE* fp = fopen("Users.dat", "rb+");
	if (fp == NULL)
	{
		printf("�ļ��򿪴���\n");
		Sleep(1000);
		return;
	}
	fread(&a, sizeof(Ac), 1, fp);
	printf("\t\t������Ҫ���ĵ��˺ţ�  ");
	scanf("%s", s);
	while (1)
	{
		if (strcmp(a.ZH, s) == 0)
		{
			break;
		}
		else
		{
			if (!feof(fp))
			{
				fread(&a, sizeof(Ac), 1, fp);
			}
			else
			{
				printf("\t\t���˺Ų����ڣ�����\n");
				fclose(fp);
				Sleep(1000);
				return;
			}
		}
	}
	printf("\t\t�˺ţ�%s   ���룺%s\n", a.ZH, a.Pass);
	printf("\t\t��ѡ��Ҫ�޸ĵ���Ŀ��  ���˺�   ������\n");
	do
	{
		scanf("%d", &num);
	} while (num < 1 || num>2);
	while (1)
	{
		switch (num)
		{
		case 1:
			printf("\t\t�µ��˺ţ�");
			scanf("%s", b.ZH);
			strcpy(a.ZH, b.ZH);
			fseek(fp, -((int)(sizeof(Ac))), SEEK_CUR);
			fprintf(fp, "%s", a.ZH);
			printf("\t\t�˺��޸ĳɹ���\n");
			Sleep(1000);
			fclose(fp);
			return;
		case 2:
			printf("\t\t�µ����룺");
			scanf("%s", b.Pass);
			strcpy(a.Pass, b.Pass);
			fseek(fp, -(((int)(sizeof(Ac)))-20), SEEK_CUR);
			fprintf(fp, "%s",a.Pass);
			printf("\t\t�����޸ĳɹ���\n");
			Sleep(1000);
			fclose(fp);
			return;
		}
	}
}



