#include"funtion.h"

//����ס����Ϣģ��
void ChangeIm()
{
	int option;//��¼ѡ��
	system("cls");
	do
	{
		printf("\t\t----------��Ϣ���Ľ���----------\n");
		printf("\t\t�ٸ���ס����Ϣ\t��ɾ��ס����Ϣ\n");
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
			ChangeStudent();
			break;
		case 2:
			delateStudent();
			break;
		}
}


/*�������ܣ���������ѧ����Ϣ
* �޷���ֵ
*/
void ChangeStudent()
{
	int n,j;//n��¼ѭ������
	char a[20],d[20];//��¼������
	int b, c;//��¼�����ͷ����
	STU* head = file_read();//��ȡ�ļ�����
	STU* p = NULL;
	STU* p1 = NULL;
	system("cls");
	printf("\t\t������Ҫ���ĵ�ѧ�������� ");
	scanf("%d", &n);
	for (j = 0; j < n; j++)
	{
		p = head;
		p1 = NULL;
		system("cls");
		printf("\t\t������Ҫ���ĵ�ѧ����Ϣ��\n");
		do
		{
			printf("\t\t��������������d(��)/x(��)    ");
			scanf("%s", a);
			printf("\t\t�����붰����");
			scanf("%d", &b);
			printf("\t\t�����뷿��ţ�");
			scanf("%d", &c);
			if ((strcmp(a, "d") && strcmp(a, "x")) || b < 0 || c < 0)
			{
				printf("\n\t\t�����������������룡����");
				Sleep(1000);
				system("cls");
			}
		} while ((strcmp(a, "d") && strcmp(a, "x")) || b < 0 || c < 0);

		printf("\t\t��Ҫ���ĵ���ϢΪ��\n");
		int flag = 0;
		while (p != NULL)
		{
			if (strcmp(a, p->data.area) == 0 && b == p->data.ridge && c == p->data.room)
			{
				printf("\t\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
				flag = 1;
			}
			p1 = p;//������һ�ڵ��ַ
			p = p->next;
		}
		if (flag == 0)
		{
			system("cls");
			printf("\n\t\tδ�ҵ�������ᣡ\n");
			Sleep(2000);
		}
		else
		{
			printf("\t\t�Ƿ���ģ� ��y/n)  ");
			while (1)
			{
				scanf("%s", d);
				if (strcmp(d, "y") == 0 || strcmp(d, "Y") == 0) break;
				if (strcmp(d, "n") == 0 || strcmp(d, "N") == 0) break;
				//������
				printf("\t\t����������������룡");
			}
			if (strcmp(d, "y") == 0 || strcmp(d, "Y") == 0)
			{
				printf("\t\t��������ĺ����Ϣ��\n");
				printf("\t\t���磺\n");
				printf("\t\t������       ¥�� ����� �������      ��λ �ѷ��䴲λ ѧԺ  (ÿ�������ÿո����,�����������ģ�\n");
				printf("\t\td(��)/x(����  1    312  m���У�/w(Ů)  4     1       jsj(�����)\n\t\t");
				STU* pi= (STU*)malloc(LEN);//�����½ڵ㱣����ĵ�����
				scanf("%s %d %d %s %d %d %s", pi->data.area, &pi->data.ridge, &pi->data.room, pi->data.roomtype, &pi->data.bed, &pi->data.rebed, pi->data.school);
				if (pi->data.bed >= pi->data.rebed)//����λ�����ѷ��䴲λ���Ϸ���������ലλ
				{
					pi->data.freebed = pi->data.bed - pi->data.rebed;
				}
				else
				{
					printf("��λ���벻�Ϸ�\n");
					free(pi);//�ͷ�p1�ռ�
					pi = NULL;//���ָ��
					Sleep(1500);
					continue;//�˳�
				}
				head = delate(a, b, c, head);//ɾ��
				pi->next = head;//���ӽڵ�
				head=pi;
				int num = save_txt(head);//������д���ļ�
				free(pi);
				pi = NULL;
				if (num > 0)
				{
					sort(num);
				}
				printf("\t\t���ĳɹ���");
			}

		}
	}
}





/*�������ܣ�����ɾ��ѧ����Ϣ
*/
void delateStudent()
{
	int n,j=0;
	char a[20],d[20];//a��¼��������d��¼�Ƿ�ɾ��
	int b, c;
	system("cls");
	printf("\n\t\t������Ҫɾ����ѧ��������");
	scanf("%d", &n);
	STU* head = file_read();
	STU* p = head;
	for (j = 0; j < n; j++)
	{
		system("cls");
		printf("\t\t������Ҫɾ����ѧ����Ϣ��\n");
		do
		{
			printf("\t\t��������������d(��)/x(��)    ");
			scanf("%s", a);
			printf("\t\t�����붰����");
			scanf("%d", &b);
			printf("\t\t�����뷿��ţ�");
			scanf("%d", &c);
			if ((strcmp(a, "d") && strcmp(a, "x")) || b < 0 || c < 0)
			{
				printf("\n\t\t�����������������룡����");
				Sleep(1000);
				system("cls");
			}
		} while ((strcmp(a, "d") && strcmp(a, "x")) || b < 0 || c < 0);

		printf("\t\t��Ҫɾ������ϢΪ��\n");
		int flag = 0;
		while (p != NULL)
		{
			if (strcmp(a, p->data.area) == 0 && b == p->data.ridge && c == p->data.room)
			{
				printf("\t\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0)
		{
			printf("\n\t\tδ�ҵ�������ᣡ\n");
		}
		else
		{
			
				printf("\t\t�Ƿ�ɾ���� ��y/n)  ");
				while (1) 
				{
					scanf("%s", d);
					if (strcmp(d, "y") == 0 || strcmp(d, "Y") == 0) break;
					if (strcmp(d, "n") == 0 || strcmp(d, "N") == 0) break;

					printf("\t\t����������������룡");
					Sleep(1500);
				}
			if (strcmp(d, "y") == 0 || strcmp(d, "Y") == 0)
			{
				head = delate(a, b, c, head);//ɾ��
				printf("\t\tɾ���ɹ���");
				Sleep(1500);
			}

		}
	}
	if (head != NULL)
	{
		save_txt(head);//��ɾ�������Ϣд���ļ�
	}
}



//ɾ���ļ������ݣ�aΪ��������bΪ������cΪ�����,headΪҪɾ��������ͷָ�룬����ɾ����������ͷָ��
STU* delate(char a[20], int b, int c,STU* head)
{
	int num = 0;
	STU* p = head,*p1=NULL;
	STU* temp = NULL;
	if (p == NULL)
	{
		return NULL;
	}
	while (p != NULL)
	{
		if (strcmp(a, p->data.area) == 0 && b == p->data.ridge && p->data.room == c)
		{//������ɾ������
			if (p==head)//��ɾ������ͷ�ڵ�
			{
				temp = p;
				head = head->next;
				p = head;
				free(temp);
			}
			else
			{
				temp = p;
				p1->next = p->next;
				free(temp);
				p = p1->next;
			}
		}
		else
		{
			p1 = p;
			p = p->next;
		}
	}
	return head;
}