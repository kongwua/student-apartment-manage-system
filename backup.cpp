#include "funtion.h"

//����ģ��

void backup()
{
	int option;
	do
	{
		system("cls");
		printf("\n\t\t�ٴ��뱸��   �ڶ�ȡ����\n");
		printf("\t\t������ѡ��:  [\t ]\b\b\b\b");
		scanf("%d", &option);
		if (option < 1 || option>2)
		{
			printf("\t\t������������������\n");
			Sleep(1500);
			system("cls");
		}
	} while (option < 1 || option>2);
	switch (option)
	{
	case 1:
		backsave1();
		break;
	case 2:
		backupsave2();
		break;
	}
}


/*�ļ����ƺ���
* ��room�ļ������ݸ��Ƶ�backup�ļ���
*/
void backsave1()
{
	STU* p = file_read();//��ȡ�ļ�����
	FILE* fp = fopen("backup.txt", "w");//����д��ʽ���ļ������ܶ�ȡ
	if (fp == NULL)
	{
		printf("¼���ļ�ʧ�ܣ�\n");//������
		return ;
	}
	while (p != NULL)
	{
		fprintf(fp, "%s %d %d %s %d %d %d %s\n", p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
		p = p->next;
	}
	fclose(fp);
	fp = NULL;//����ļ�ָ��
	printf("\t\t���ݱ��ݳɹ�\n");
	Sleep(2000);
	system("cls");
}


//��backup�ļ��е�����д��room�ļ���
void backupsave2()
{
	//��ȡbackup�ļ�����
	STU* p1 = NULL, * p2 = NULL, * head = NULL;//��������ָ��
	p1 = p2 = (STU*)malloc(LEN);//������һ���ڵ�������Žṹ���ڵ�����
	FILE* fp = fopen("backup.txt", "rt+");//�����ļ�ָ�룬��ȡ�ļ�����
	int k = fgetc(fp);
	if (k == EOF)  return ;//���򿪵��ǿ��ļ�������NULL
	rewind(fp);//���ļ�ָ��ָ�ؿ�ͷ
	if (p1 != NULL && fp != NULL)
	{
		i = 0;//i��������
		while (!feof(fp))//���ļ�δ�ﵽ��βʱ��ѭ������
		{
			fscanf(fp, "%s %d %d %s %d %d %d %s\n", p1->data.area, &p1->data.ridge, &p1->data.room, p1->data.roomtype, &p1->data.bed, &p1->data.rebed, &p1->data.freebed, p1->data.school);
			if (i == 0) head = p1;//��¼ͷָ��
			else p2->next = p1;
			p2 = p1;
			p1 = (STU*)malloc(LEN);
			i++;
		}
		free(p1);//�ͷ�p1�������Ŀռ䣻
		p2->next = NULL;//�����βΪ��ָ��
	}
	else
	{
		printf("\t\t�ļ���ȡ�������˳����ԣ�\n");
	}
	if (fp != NULL) fclose(fp);

   //д��room�ļ�
	STU* p = head;
	FILE* fg = fopen("room.txt", "w");//����д��ʽ���ļ������ܶ�ȡ
	if (fg == NULL)
	{
		printf("¼���ļ�ʧ�ܣ�\n");//������
		return;
	}
	while (p != NULL)
	{
		fprintf(fg, "%s %d %d %s %d %d %d %s\n", p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
		p = p->next;
	}
	fclose(fg);
	fg = NULL;//����ļ�ָ��
	printf("\t\t���ݶ�ȡ�ɹ�\n");
	Sleep(2000);
	system("cls");
}