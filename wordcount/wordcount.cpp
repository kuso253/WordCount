#include<stdio.h>
#include<string.h>
int main(int argc, char** argv)
{
	if (argc < 3)
	{
		printf("�������������淶����\n");
		printf("��ʾ:ʹ��-c:ͳ���ַ���\n");
		printf("     ʹ��-w:ͳ�Ƶ�����\n");
		return 0;
	}
	if (strcmp("-c", argv[1])==0) {
		char str[1000];
		FILE* fp;
		if (fopen_s(&fp, argv[2], "r")==0)
		{
			int counter = 0;
			while (fgets(str, 1000, fp) != NULL)
			{
				int j = 0;
				while (str[j] != '\0')
				{
					counter++;
					j++;
				}
			}
			printf("���ļ��������ַ���Ϊ:%d\n", counter);
		}
		else
		{
			printf("�ļ���ʧ��\n");
		}
	}
	else if (strcmp("-w", argv[1]) == 0)
	{
		char str[1000];
		FILE* fp;
		if (fopen_s(&fp, argv[2], "r") == 0)
		{
			int counter = 0;
			while (fgets(str, 1024, fp) != NULL)
			{
				int j = 0;
				while (str[j] != '\0')
				{
					if(str[0] != '\0' && (str[0] == ' ' || str[0] == ',' || str[0] == '.'))
						while (str[j] == ' ' || str[j] == ',' || str[j] == '.') j++;

					if (str[j]!='\0' && (str[j] == ' ' || str[j] == ',' || str[j] == '.'))
					{
						counter++;
						while (str[j] == ' ' || str[j] == ',' || str[j] == '.') j++;
					}
					j++;
				}
				if (j != 0) counter++;
			}
			printf("���ļ������ĵ�����Ϊ:%d\n", counter);
		}
		else
		{
			printf("�ļ���ʧ��\n");
		}
	}
	else
	{
		printf("�������������淶����\n");
		printf("��ʾ:ʹ��-c:ͳ���ַ���\n");
		printf("     ʹ��-w:ͳ�Ƶ�����\n");
	}
	return 0;
}
