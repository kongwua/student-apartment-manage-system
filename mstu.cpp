#include "funtion.h"


//管理学生账号
void ManageStu()
{
	int option;//记录选择
	system("cls");
	do
	{
		printf("\t\t----------学生账号管理界面----------\n");
		printf("\t\t①查看学生账号信息\t②修改学生账号信息\n");
		printf("\t\t请输入选项:  [\t ]\b\b\b\b");
		scanf("%d", &option);
		if (option < 1 || option>2)
		{
			printf("\t\t输入有误，请重新输入\n");
			Sleep(1000); 
			system("cls");
		}
	} while (option < 1 || option>2);
	switch (option)
	{
	 case 1:
		 look();//查看学生账号信息
		 break;
	 case 2:
		 change();//更改学生账号信息
		 break;
	}
}




//查看学生账号信息
void look()
{
	system("cls");
	FILE* fp = fopen("Users.dat","rb+");
	char k=fgetc(fp);
	if (k == EOF)
	{
		printf("文件中无信息！");
		Sleep(2000);
		return;
	}
	rewind(fp);
	Ac a;
	fread(&a, sizeof(Ac), 1, fp);
	while (1)
	{
		printf("\t\t账号：%s\n\t\t密码：%s\n\n", a.ZH, a.Pass);
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


//更改学生账号
void change()
{
	system("cls");
	Ac a, b;
	int num;
	char s[20];//保存账号
	FILE* fp = fopen("Users.dat", "rb+");
	if (fp == NULL)
	{
		printf("文件打开错误！\n");
		Sleep(1000);
		return;
	}
	fread(&a, sizeof(Ac), 1, fp);
	printf("\t\t请输入要更改的账号：  ");
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
				printf("\t\t该账号不存在！！！\n");
				fclose(fp);
				Sleep(1000);
				return;
			}
		}
	}
	printf("\t\t账号：%s   密码：%s\n", a.ZH, a.Pass);
	printf("\t\t请选择要修改的项目：  ①账号   ②密码\n");
	do
	{
		scanf("%d", &num);
	} while (num < 1 || num>2);
	while (1)
	{
		switch (num)
		{
		case 1:
			printf("\t\t新的账号：");
			scanf("%s", b.ZH);
			strcpy(a.ZH, b.ZH);
			fseek(fp, -((int)(sizeof(Ac))), SEEK_CUR);
			fprintf(fp, "%s", a.ZH);
			printf("\t\t账号修改成功！\n");
			Sleep(1000);
			fclose(fp);
			return;
		case 2:
			printf("\t\t新的密码：");
			scanf("%s", b.Pass);
			strcpy(a.Pass, b.Pass);
			fseek(fp, -(((int)(sizeof(Ac)))-20), SEEK_CUR);
			fprintf(fp, "%s",a.Pass);
			printf("\t\t密码修改成功！\n");
			Sleep(1000);
			fclose(fp);
			return;
		}
	}
}



