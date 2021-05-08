#include<stdio.h>
#include<string.h>
int main(int argc, char** argv)
{
	if (argc < 3)
	{
		printf("参数输入错误，请规范操作\n");
		printf("提示:使用-c:统计字符数\n");
		printf("     使用-w:统计单词数\n");
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
			printf("该文件包含的字符数为:%d\n", counter);
		}
		else
		{
			printf("文件打开失败\n");
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
			printf("该文件包含的单词数为:%d\n", counter);
		}
		else
		{
			printf("文件打开失败\n");
		}
	}
	else
	{
		printf("参数输入错误，请规范操作\n");
		printf("提示:使用-c:统计字符数\n");
		printf("     使用-w:统计单词数\n");
	}
	return 0;
}
