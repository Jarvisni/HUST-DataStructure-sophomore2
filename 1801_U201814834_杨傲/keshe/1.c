#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>
#define TYPESIZE sizeof(struct veg_type)
#define INFORMSIZE sizeof(struct veg_inform)
#define PLANSIZE sizeof(struct veg_plan)
void load();                       //README：
void Failure();                    //函数前注释均在后方有标注，此处只是函数声明。不再复制粘贴注释过来了
void addType();                    //均按照要求函数间空行，多多加以注释
void save();
void changeType();
void deleteType();
void addInfo();
void changeInfo();
void deleteInfo();
void addPlan();
void changePlan();
void deletePlan();
void searchType(int);
void searchZich();
void searchFen();
void searchYear();
void searchName();
void count1Year();
void count2Years();
void countSum(int);
void countNu(char*);
char* isZich(char* s, char* t);
void printData();
int hang2 = 0;                      //获取第二个表中行数（除第一行以外）
int hang3 = 0;                      //获取第三个表中行数（除第一行以外）即种植计划已有的加载进去的数量

typedef struct veg_type{
    char TypeCode;                  //分类编码
    char TypeName[8];               //分类描述
    struct veg_type *nexttype;      //指向下一个蔬菜类型
    struct veg_inform *nextinf;     //指向下一个蔬菜信息
}*PType;
struct veg_type *headv = NULL;
struct veg_type *hp1 = NULL;

typedef struct veg_inform{
    char VegName[20];               //蔬菜名称
    int VegCode;                    //蔬菜编号
    int VegType;                    //蔬菜类别编号
    char VegNutri[50];              //蔬菜营养成分,20个不够，开成50个
    struct veg_inform *nextinfo;    //指向下一个蔬菜信息
    struct veg_plan *nextplan;      //指向下一个种植信息
}*PInfo;
struct veg_inform *headi = NULL;

typedef struct veg_plan{
    int PlanCode;					//种植编号
    int PlanVegCode;				//蔬菜编号，和前一个蔬菜编号相同
    int PlanArea;					//种植面积
    float PlanWeight;				//收获重量
    char PlanYear[5];				//种植年份
    struct veg_plan *next;          //指向下一个种植信息
}*PPlan;
struct veg_plan *headp = NULL;


//显示菜单
void showMenu0()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("1、数据维护      2、数据查询      3、数据统计      4、保存退出\n");
	printf("5、显示当前所有数据\n");
	printf("源数据已加载！Source data Loaded！\n");
	printf("请选择执行的功能：（输入1~5）\n");
}


//显示菜单
void showMenu1()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("1、蔬菜种类信息维护  2、蔬菜基本信息维护  3、蔬菜种植信息维护\n");
	printf("请选择要维护的功能：（1~3)\n");
	printf("输入4：返回\n");
}


//显示菜单
void showMenu1_1()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("1、新增节点        2、修改节点        3、删除节点      4、返回\n");
	printf("请选择要执行的功能：（1~4)\n");
}


//显示菜单
void showMenu1_2()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("1、新增节点        2、修改节点        3、删除节点      4、返回\n");
	printf("请选择要执行的功能：（1~4)\n");
}


//显示菜单
void showMenu1_3()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("1、新增节点        2、修改节点        3、删除节点      4、返回\n");
	printf("请选择要执行的功能：（1~4)\n");
}


//显示菜单
void showMenu2()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("1、蔬菜种类信息查询  2、蔬菜基本信息查询  3、蔬菜种植信息查询\n");
	printf("请选择要查询的功能：（1~3)\n");
	printf("输入4：返回\n");
}


//显示菜单
void showMenu2_1()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("请输入想要查询的蔬菜的分类编号（int）\n");
	printf("输入0返回\n");
}


//显示菜单
void showMenu2_2()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("请输入想要查询的方式（int）\n");
	printf("1、蔬菜名称子串查找             2、分类码及营养成分查找\n");
	printf("输入0返回\n");
}


//显示菜单
void showMenu2_3()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("请输入想要查询的方式（int）\n");
	printf("1、名称子串及年份查找             2、蔬菜名称查找\n");
	printf("输入0返回\n");
}


//显示菜单
void showMenu3()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("1、某年统计  2、起止年份统计  3、某种已有数量  4、营养成分统计\n");
	printf("请选择要统计的功能：（1~3)\n");
	printf("输入5：返回\n");
}


//显示菜单
void showMenu3_1()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("请输入想要查询的年份（char[5]）\n");                            //自动返回
}


//显示菜单
void showMenu3_2()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("请输入想要查询的起止年份（char[5] char[5]）\n");                 //自动返回
}


//显示菜单
void showMenu3_3()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("请输入想要查询的蔬菜的分类编号（int）\n");
	printf("输入0返回\n");
}


//显示菜单
void showMenu3_4()
{
	system("cls");
	printf("---------------------菜农种植信息管理系统---------------------\n");
	printf("请输入想要查询的蔬菜的营养成分子串（char[20]）\n");              //自动返回
}

//主函数
int main()
{
	int opt = 0;
	int opt2 = 0;
	int opt3 = 0;
	PType p=NULL;
	system("color 0d");
	showMenu0();
	load();
	p = headv->nexttype;
	scanf("%d", &opt);
	getchar();
	while (opt != 4)
	{
		if (opt == 1)
		{
			showMenu1();
			scanf("%d", &opt2);
			getchar();
			while (opt2 != 4)
			{
				if (opt2 == 1)
				{
					showMenu1_1();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 4)
					{

						if (opt3 == 1)
						{
							addType();
							printData();                //为了便于检查，在功能执行结束后将所有信息输出一遍，可以将此句直接注释掉，不影响实际功能
						}
						else if (opt3 == 2)
						{
							changeType();
							printData();                //为了便于检查，在功能执行结束后将所有信息输出一遍，可以将此句直接注释掉，不影响实际功能
						}
						else if (opt3 == 3)
						{
							deleteType();
							printData();                //为了便于检查，在功能执行结束后将所有信息输出一遍，可以将此句直接注释掉，不影响实际功能
						}
						showMenu1_1();
						scanf("%d", &opt3);
						getchar();
					}
				}
				else if (opt2 == 2)
				{
					showMenu1_2();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 4)
					{

						if (opt3 == 1)
						{
							addInfo();
							printData();                //为了便于检查，在功能执行结束后将所有信息输出一遍，可以将此句直接注释掉，不影响实际功能
						}
						else if (opt3 == 2)
						{
							changeInfo();
							printData();                //为了便于检查，在功能执行结束后将所有信息输出一遍，可以将此句直接注释掉，不影响实际功能
						}
						else if (opt3 == 3)
						{
							deleteInfo();
							printData();                //为了便于检查，在功能执行结束后将所有信息输出一遍，可以将此句直接注释掉，不影响实际功能
						}
						showMenu1_2();
						scanf("%d", &opt3);
						getchar();
					}
				}
				else if (opt2 == 3)
				{
					showMenu1_3();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 4)
					{

						if (opt3 == 1)
						{
							addPlan();
							printData();                //为了便于检查，在功能执行结束后将所有信息输出一遍，可以将此句直接注释掉，不影响实际功能
						}
						else if (opt3 == 2)
						{
							changePlan();
							printData();                //为了便于检查，在功能执行结束后将所有信息输出一遍，可以将此句直接注释掉，不影响实际功能
						}
						else if (opt3 == 3)
						{
							deletePlan();
							printData();                //为了便于检查，在功能执行结束后将所有信息输出一遍，可以将此句直接注释掉，不影响实际功能
						}
						showMenu1_3();
						scanf("%d", &opt3);
						getchar();
					}
				}
				showMenu1();
				scanf("%d", &opt2);
				getchar();
			}
		}
		else if (opt == 2)
		{
			showMenu2();
			scanf("%d", &opt2);
			getchar();
			while (opt2 != 4)
			{

				if (opt2 == 1)
				{
					showMenu2_1();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 0)
					{
						searchType(opt3);
						showMenu2_1();
						scanf("%d", &opt3);
						getchar();
					}
				}
				else if (opt2 == 2)
				{
					showMenu2_2();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 0)
					{
						if (opt3 == 1)
						{
							searchZich();
						}
						else if (opt3 == 2)
						{
							searchFen();
						}
						showMenu2_2();
						scanf("%d", &opt3);
						getchar();
					}
				}
				else if (opt2 == 3)
				{
					showMenu2_3();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 0)
					{
						if (opt3 == 1)
						{
							searchYear();
						}
						else if (opt3 == 2)
						{
							searchName();
						}
						showMenu2_3();
						scanf("%d", &opt3);
						getchar();
					}
				}
				showMenu2();
				scanf("%d", &opt2);
				getchar();
			}
		}
		else if (opt == 3)
		{
			showMenu3();
			scanf("%d", &opt2);
			getchar();
			while (opt2 != 5)
			{

				if (opt2 == 1)
				{
					showMenu3_1();
					count1Year();
				}
				else if (opt2 == 2)
				{
					showMenu3_2();
					count2Years();
				}
				else if (opt2 == 3)
				{
					showMenu3_3();
					scanf("%d", &opt3);
					getchar();
					while (opt3 != 0)
					{
						countSum(opt3);
						showMenu3_3();
						scanf("%d", &opt3);
						getchar();
					}
				}
				else if (opt2 == 4)
				{
					showMenu3_4();
					char tempNu[20];
					scanf("%s", tempNu);
					getchar();
					countNu(tempNu);
				}
				showMenu3();
				scanf("%d", &opt2);
				getchar();
			}
		}
		else if (opt == 5)
		{
			printData();
		}
		showMenu0();
		scanf("%d", &opt);
		getchar();
	}

	printf("信息已保存并导出，欢迎您下次使用！\n");
	printf("Information Saved!  Welcome Next Time!\n");
	save();                                                 //保存并导出基础的三个，另外两个导出功能一个是前面searchName在查找某蔬菜名后自动导出，另一个是前面count1Year功能在统计某年后自动导出
	
}

//加载信息
void load()
{
	//进行种类节点的构造和读取数据并加载
    PType p,p1;
    FILE *fp;
    if( (fp = fopen("蔬菜种类.csv", "ab+")) == NULL)     //加载进去蔬菜种类信息
        Failure();
    fseek(fp, 20L, SEEK_SET);                           //跳过csv中第一行标题行
    char delims[] = ",";
    char *line,*record;
    char buffer[1024];
    p = (PType)malloc(TYPESIZE);
    headv = p;
    p1 = (PType)malloc(TYPESIZE);
    p->nexttype = p1;
    p = p1;
    int i=1, j=1;
    int hang = 0,lie=1;                                     
    while(( line = fgets(buffer, sizeof(buffer), fp))!=NULL)//获取行数(除第一行以外)
    {
        hang++;
    }
    fseek(fp, 20L, SEEK_SET);                            //重新复位到跳过第一行后的位置
    /*while((*/ line = fgets(buffer, sizeof(buffer), fp); /*)!=NULL)*/
    //{                                                  //读了一行的数据
    record = strtok(line, ",");                          //取两次，第一次是第一列舍去不用
    record = strtok(NULL, ",");                          //取两次，第二次是第二列开始用
    while (record != NULL)                               
    {
        sprintf(p->TypeName,"%s", record);               //将读到的信息通过sprintf传给节点
        p->TypeCode = j;
        int l = 0;
        for (l = 0; l < 8;l++)                           //通过此循环将TypeName中可能含有的回车换行删去
        {
            if((p->TypeName[l]=='\r')||(p->TypeName[l]=='\n'))
                p->TypeName[l] = '\0';
        }
        //fscanf(fp, "%s", &(p->TypeName));
        p1 = (PType)malloc(TYPESIZE);
        p->nexttype = p1;
        p = p1;
        // if (j == lie)                                      //从有用的第一列开始读取五列
        //     break;
        j++;
        record = strtok(NULL, ",");
    }
    p->nexttype = NULL;
    lie = j;                                                  //获取列数（除第一列之外）即蔬菜种类数
    j = 1;
    //}
    fclose(fp);
    fp = NULL;
    p = headv->nexttype;
	while (p != NULL)
	{
		p->nextinf = NULL;
		p = p->nexttype;
	}




	//进行信息节点的构造和读取数据并加载
	PInfo p2, p3;
    i = 1;
    j = 1;
	
    int temp;
    int k = 1;                                          //i、j、k、temp均为计数用
    int TempCode = 0;
    char TempName[20];
    FILE *fp2;
    if( (fp2 = fopen("蔬菜信息.csv", "ab+")) == NULL)    //加载进去蔬菜种类信息
        Failure();
    fseek(fp2, 35L, SEEK_SET);                           //跳过csv中第一行标题行
    //char delims[] = ",";
    char *line2,*record2;
    char buffer2[1024];

	while ((line2 = fgets(buffer2, sizeof(buffer2), fp2)) != NULL)//获取行数(除第一行以外)即蔬菜个数
	{
		hang2++;
	}
	fseek(fp2, 35L, SEEK_SET);

    while(( line2 = fgets(buffer2, sizeof(buffer2), fp2))!=NULL)
    {         
		p2 = (PInfo)malloc(INFORMSIZE);
		p2->nextinfo = NULL;
		p2->nextplan = NULL;
        record2 = strtok(line2, ",");                        //第一次是第一列
        while (record2 != NULL)                               
        {
            if(j==1)
            {
                //TempCode = (*record2) - '0';                 //暂存信息供以后赋值
				sscanf(record2, "%d", &TempCode);
                record2 = strtok(NULL, ",");
                j++;
                continue;
            }
            if(j==2)
            {
                sprintf(TempName,"%s", record2);             //暂存信息供以后赋值
                record2 = strtok(NULL, ",");
                j++;
                continue;
            }
            if(j==3)
            {
				
                //temp = (*record2) - '0';                  //暂存信息供以后赋值,将此语句功能用sscanf替换
				sscanf(record2, "%d", &temp);
				p = headv->nexttype;
                for (k = 1; k < temp;k++)
                {
                    p = p->nexttype;                        //找到对应的蔬菜种类下面添加蔬菜信息
                }
				if ((p->nextinf) == NULL)
				{
					p->nextinf = p2;
					headi = p2;
				}
				p2 = p->nextinf;
                while((p2->nextinfo)!=NULL)
                {
                    p2 = p2->nextinfo;
                }
                p2->VegCode = TempCode;                          //赋值
                sprintf(p2->VegName,"%s", TempName);
                p2->VegType = temp;
                record2 = strtok(NULL, ",");
                j++;
                continue;
            }
            if(j==4)
            {
                sprintf(p2->VegNutri,"%s", record2);
                int l = 0;
                for (l = 0; l < 50;l++)                           //通过此循环将VegNutri中可能含有的回车换行删去
                {
                    if((p2->VegNutri[l]=='\r')||(p2->VegNutri[l]=='\n'))
                        p2->VegNutri[l] = '\0';
                }
                break;
            }
            
        }
		p3 = (PInfo)malloc(INFORMSIZE);
		p2->nextinfo = p3;
		p2 = p3;
		p2->nextinfo = NULL;
		p2->nextplan = NULL;
		j = 1;
    }
    fclose(fp2);
    fp2 = NULL;
    /*p2->nextinfo = NULL;*/
    p = headv->nexttype;






	//进行计划节点的构造和读取数据并加载
	PPlan p4, p5;
	i = 1; j = 1; k = 1;
	float tempw = 0;                                     //用于暂时记录重量
	FILE* fp3;
	if ((fp3 = fopen("种植信息.csv", "ab+")) == NULL)    //加载进去蔬菜种类信息
		Failure();
	fseek(fp3, 42L, SEEK_SET);                           //跳过csv中第一行标题行
	char* line3, * record3;
	char buffer3[1024];

	while ((line3 = fgets(buffer3, sizeof(buffer3), fp3)) != NULL)//获取行数(除第一行以外)即蔬菜个数
	{
		hang3++;
	}
	fseek(fp3, 42L, SEEK_SET);

	while ((line3 = fgets(buffer3, sizeof(buffer3), fp3)) != NULL)
	{
		p4 = (PPlan)malloc(PLANSIZE);
		p4->next = NULL;
		record3 = strtok(line3, ",");                         //第一次是第一列
		while (record3 != NULL)
		{
			if (j == 1)
			{
				//TempCode = (*record3) - '0';                //暂存信息供以后赋值
				sscanf(record3, "%d", &TempCode);
				record3 = strtok(NULL, ",");
				j++;
				continue;
			}
			if (j == 2)
			{
				int sum = 0;
				int flag = 0;							      //来记录未找到
				//temp = (*record3) - '0';                    //暂存信息供以后赋值
				sscanf(record3, "%d", &temp);
				p = headv->nexttype;
				PInfo pt;
				pt = p->nextinf;
				for (k = 1; k <= lie; k++)
				{
					//PInfo pt;
					pt = p->nextinf;
					while (pt != NULL)
					{
						pt = pt->nextinfo;
						sum++;
					}
					pt = p->nextinf;
					for (i = 1; i < sum; i++)				//以免读取最后一个为空的节点
					{
						if (pt->VegCode == temp)
						{
							flag = 1;						//来记录找到了
							break;
						}
						else
						{
							pt = pt->nextinfo;
						}
					}
					if (flag == 1)
					{
						break;
					}
					else
					{
						sum = 0;
						p = p->nexttype;
					}
				}
				if (flag == 0)
				{
					printf("蔬菜编号为%d的蔬菜信息未找到！\n",temp);        //用于当要载入某蔬菜编号的蔬菜但是系统未录入这个蔬菜编号时
					record3 = strtok(NULL, ",");
					j++;
					continue;
				}
				else
				{
					if (pt->nextplan == NULL)
					{
						pt->nextplan = p4;
						headp = p4;
					}
					p4 = pt->nextplan;
					while ((p4->next) != NULL)
					{
						p4 = p4->next;
					}
					p4->PlanCode = TempCode;
					p4->PlanVegCode = temp;
					record3 = strtok(NULL, ",");
					j++;
					continue;
				}
			}
			if (j == 3)
			{
				//TempCode = (*record3) - '0';                 //暂存信息供以后赋值
				sscanf(record3, "%d", &TempCode);
				p4->PlanArea = TempCode;
				record3 = strtok(NULL, ",");
				j++;
				continue;
			}
			if (j == 4)
			{
				sscanf(record3, "%f", &tempw);
				p4->PlanWeight = tempw;
				record3 = strtok(NULL, ",");
				j++;
				continue;
			}
			if (j == 5)
			{
				sprintf(p4->PlanYear, "%s", record3);
				int l = 0;
				for (l = 0; l < 5; l++)                           //通过此循环将OlanYear中可能含有的回车换行删去
				{
					if ((p4->PlanYear[l] == '\r') || (p4->PlanYear[l] == '\n'))
						p4->PlanYear[l] = '\0';
				}
				break;
			}
		}
		j = 1;
		p5 = (PPlan)malloc(PLANSIZE);
		p4->next = p5;
		p4 = p5;
		p4->next = NULL;
	}
	fclose(fp3);
	fp3 = NULL;
	/*p4->next = NULL;*/
	p = headv->nexttype;

}



//用于在打开文件时没能够成功fopen时报错，也可以另外用于malloc是否成功的判定，但在写代码时没有这样做
void Failure()
{
    printf("操作失败，存在错误！\n");
    system("pause");
    return 0;
}


//实现增加种类，入口出口参数无。
void addType()
{
	PType p;
	PType p1;
	int i = 1;
	char tempName[8];
	p1 = headv->nexttype;					  //p1指向当前节点，p指向它下一个节点
	p = p1->nexttype;
	while (p != NULL)						  //最后p1会指向最后一个节点此时p==NULL，因为数据结构的构造导致每次结尾多一个节点并指空
	{
		p1 = p1->nexttype;                    //p1从第一个种类向后遍历
		p = p->nexttype;
		i++;
	}
	printf("请输入想要增加的种类名称（char[8])\n");
	scanf("%s", tempName);
	getchar();
	sprintf(p1->TypeName, "%s", tempName);    //向p1节点赋值
	p1->TypeCode = i;
	p1->nextinf = NULL;
	p = (PType)malloc(TYPESIZE);              //构造新结点接在后面，保持结构
	p->nexttype = NULL;
	p->nextinf = NULL;
	p1->nexttype = p;
	printf("添加种类成功!Add Type Successfully!\n");
	system("pause");
	
	
}


//实现改变种类，入口出口参数无。
void changeType()
{
	PType p;
	PType p1;
	int i = 1;
	char tempName[8];
	int temp;
	p1 = headv->nexttype;
	p = p1->nexttype;
	printf("请选择输入你想要改变的蔬菜种类或者其分类编号\n");
	printf("1、蔬菜种类              2、分类编号\n");
	scanf("%d", &i);                                             //两种功能选择一种进行输入
	if (i == 1)
	{
		scanf("%s", tempName);
		getchar();
		while (strcmp(p1->TypeName, tempName) != 0)              //判定是否找到
		{
			p1 = p1->nexttype;
			p = p->nexttype;
		}
	}
	else if (i == 2)
	{
		scanf("%d", &temp);
		getchar();
		while (p1->TypeCode != temp)                              //判定是否找到
		{
			p1 = p1->nexttype;
			p = p->nexttype;
		}
	}
	printf("请输入你想要把它改变成为的蔬菜种类(char[8])\n");     //蔬菜编号不打算更改，若是更改要改变好多东西，仅仅修改此处做到后弃用
	scanf("%s", tempName);
	getchar();
	sprintf(p1->TypeName, "%s", tempName);                       //将信息通过sprintf传给节点
	int l = 0;
	for (l = 0; l < 8; l++)                                      //通过此循环将TypeName中可能含有的回车换行删去
	{
		if ((p->TypeName[l] == '\r') || (p->TypeName[l] == '\n'))
			p->TypeName[l] = '\0';
	}
	printf("修改完成！Successfully Changed！\n");
	system("pause");

}


//实现删除种类，入口出口参数无。
void deleteType()
{
	PType p;
	PType p1;
	PType pb;                                                    //p1指向当前节点，p指向下一个，pb指向前一个
	int i = 1;
	char tempName[8];
	int temp;
	pb = headv;
	p1 = headv->nexttype;
	p = p1->nexttype;
	printf("请选择输入你想要删除的蔬菜种类或者其分类编号\n");
	printf("1、蔬菜种类              2、分类编号\n");            //二选一进行输入
	scanf("%d", &i);
	if (i == 1)
	{
		scanf("%s", tempName);
		getchar();
		while (strcmp(p1->TypeName, tempName) != 0)              //判定是否找到
		{
			pb = pb->nexttype;
			p1 = p1->nexttype;
			p = p->nexttype;
		}
		pb->nexttype = p;
		p1->nexttype = NULL;
	}
	else if (i == 2)
	{
		scanf("%d", &temp);
		getchar();
		while (p1->TypeCode != temp)                             //判定是否找到
		{
			pb = pb->nexttype;
			p1 = p1->nexttype;
			p = p->nexttype;
		}
		pb->nexttype = p;
		p1->nexttype = NULL;
	}
	printf("删除完成！Successfully Deleted！\n");
	system("pause");

}



//实现增加信息，入口出口参数无。
void addInfo()
{
	PType p;
	PType p1;
	int i = 1;
	char tempName[8];
	char tempNu[50];
	int temp=0;
	p1 = headv->nexttype;
	p = p1->nexttype;
	PInfo p3=NULL, p4=NULL;
	printf("请输入想要增加的信息所属分类码（int)\n");
	scanf("%d", &temp);
	getchar();
	printf("请输入想要增加的信息的蔬菜名称（char[8])\n");
	scanf("%s", tempName);
	getchar();
	printf("请输入想要增加的信息的营养成分（char[50])\n");
	scanf("%s", tempNu);
	getchar();
	while (p1->TypeCode != temp)               //判定是否找到
	{
		p1 = p1->nexttype;
		p = p->nexttype;
	}
	p3 = p1->nextinf;
	if (p3 == NULL)                            //来判定进行当这个种类只有一个菜却被删掉之后无菜或是本身就无菜的情况
	{										   //此时需要新建节点接在后面
		p4 = (PInfo)malloc(INFORMSIZE);
		p4->nextinfo = NULL;
		p4->nextplan = NULL;
		p3 = p4;
		p1->nextinf = p3;
	}
	p4 = p3->nextinfo;
	while (p4 != NULL)						  //最后p4指向最后一个节点，由于构造所以每次结尾多一个节点并指空
	{
		p4 = p4->nextinfo;
		p3 = p3->nextinfo;
	}
	p3->VegType = p1->TypeCode;               //向节点赋值
	p3->VegCode = ++hang2;
	sprintf(p3->VegName, "%s", tempName);
	sprintf(p3->VegNutri, "%s", tempNu);
	p3->nextinfo = NULL;
	p3->nextplan = NULL;
	p4 = (PInfo)malloc(INFORMSIZE);          //构建新结点在后面保持结构
	p4->nextinfo = NULL;
	p4->nextplan = NULL;
	p3->nextinfo = p4;
	printf("添加信息成功!Add Information Successfully!\n");
	system("pause");

}



//实现修改信息，入口出口参数无。
void changeInfo()
{
	PType p;
	PType p1;
	int i = 1;
	char tempName[8];
	char tempNu[50];
	int temp;
	p1 = headv->nexttype;
	p = p1->nexttype;
	PInfo p3 = NULL, p4 = NULL;
	printf("请选择输入你想要改变的蔬菜信息中的蔬菜编号或者其名称\n");
	printf("1、蔬菜名称              2、蔬菜编号\n");
	scanf("%d", &i);
	if (i == 1)
	{
		scanf("%s", tempName);
		getchar();
		p3 = p1->nextinf;
		p4 = p3->nextinfo;
		
		while (strcmp(p3->VegName, tempName) != 0)              //判定是否找到
		{
			p3 = p3->nextinfo;
			p4 = p4->nextinfo;
			if (p4 == NULL)                                    //此信息链找完，换下一个种类对应的信息链
			{
				p1 = p1->nexttype;
				p3 = p1->nextinf;
				p4 = p3->nextinfo;
			}
		}
	}
	else if (i == 2)
	{
		scanf("%d", &temp);
		getchar();
		p3 = p1->nextinf;
		p4 = p3->nextinfo;

		while (p3->VegCode!=temp)                               //判定是否找到
		{
			p3 = p3->nextinfo;
			p4 = p4->nextinfo;
			if (p4 == NULL)                                     //此信息链找完，换下一个种类对应的信息链
			{
				p1 = p1->nexttype;
				p3 = p1->nextinf;
				p4 = p3->nextinfo;
			}
		}
	}
	printf("请输入想要改成的蔬菜名称（char[8])\n");
	scanf("%s", tempName);
	getchar();
	printf("请输入想要改成的营养成分（char[50])\n");
	scanf("%s", tempNu);
	getchar();
	sprintf(p3->VegName, "%s", tempName);
	sprintf(p3->VegNutri, "%s", tempNu);
	printf("修改完成！Successfully Changed！\n");
	system("pause");
}



//实现修改信息，入口出口参数无。
void deleteInfo()
{
	PType p;
	PType p1;
	PType ptemp;
	int i = 1;
	char tempName[8];
	int temp;
	p1 = headv->nexttype;
	p = p1->nexttype;
	PInfo p3 = NULL, p4 = NULL, pb = NULL;
	printf("请选择输入你想要删除的蔬菜信息中的蔬菜编号或者其名称\n");
	printf("1、蔬菜名称              2、蔬菜编号\n");
	scanf("%d", &i);
	if (i == 1)
	{
		scanf("%s", tempName);
		getchar();
		p3 = p1->nextinf;
		p4 = p3->nextinfo;
		while (strcmp(p3->VegName, tempName) != 0)                        //判定是否找到
		{
			pb = p3;
			p3 = p3->nextinfo;
			p4 = p4->nextinfo;
			if (p4 == NULL)                                              //此信息链找完，换下一个种类对应的信息链
			{
				p1 = p1->nexttype;
				p3 = p1->nextinf;
				p4 = p3->nextinfo;
				pb = NULL;                                                 //若pb有所指，则指向p3前一个节点，若为空，则pb应该为PType节点，即要将第一个信息节点删去
			}
		}
	}
	else if (i == 2)
	{
		scanf("%d", &temp);
		getchar();
		p3 = p1->nextinf;
		p4 = p3->nextinfo;
		while (p3->VegCode != temp)                                        //判定是否找到
		{
			pb = p3;
			p3 = p3->nextinfo;
			p4 = p4->nextinfo;
			if (p4 == NULL)                                                 //此信息链找完，换下一个种类对应的信息链
			{
				p1 = p1->nexttype;
				p3 = p1->nextinf;
				p4 = p3->nextinfo;
				pb = NULL;
			}
		}
	}
	if (pb == NULL)                                                          //pb==NULL此情况意味着此时p3信息节点为种类节点后跟的第一个种类节点，故pb此时不是p3的前一个信息节点而是种类节点
	{
		ptemp = headv->nexttype;
		while (ptemp->nextinf != p3)
		{
			ptemp = ptemp->nexttype;
		}
		ptemp->nextinf = p4;
		p3->nextinfo = NULL;
	}
	else                                                                     //不为空即找到了信息链中的p3以及其前后节点
	{
		pb->nextinfo = p4;
		p3->nextinfo = NULL;
	}
	printf("删除完成！Successfully Deleted！\n");
	hang3--;
	system("pause");
}



//实现增加计划，入口出口参数无。
void addPlan()
{
	PType p;
	PType p1;
	int i = 1;
	int temp;
	int temparea;
	float tempw;
	char tempYear[5];
	p1 = headv->nexttype;
	p = p1->nexttype;
	printf("请输入想要给哪种蔬菜增加新的种植信息（蔬菜编号int）\n");
	scanf("%d", &temp);
	getchar();
	printf("请输入新增的种植信息中的种植面积（int)\n");
	scanf("%d", &temparea);
	getchar();
	printf("请输入新增的种植信息中的收获重量（float)\n");
	scanf("%f", &tempw);
	getchar();
	printf("请输入新增的种植信息中的种植年份(char[5])\n");                     //默认新增的计划年份和已存在的年份均不同，不同的种植信息用蔬菜编号和年份进行区分
	scanf("%s", tempYear);
	getchar();
	PInfo p3 = NULL, p4 = NULL;
	p3 = p1->nextinf;
	p4 = p3->nextinfo;
	while (p3->VegCode != temp)												  //判定是否找到
	{
		p3 = p3->nextinfo;
		p4 = p4->nextinfo;
		if (p4 == NULL)                                                    //此信息链找完，换下一个种类对应的信息链
		{
			p1 = p1->nexttype;
			p3 = p1->nextinf;
			p4 = p3->nextinfo;
		}
	}
	PPlan p5, p6;
	p5 = p3->nextplan;
	if (p5 == NULL)                                                           //来完成当这个种类只有一个菜却被删掉之后无菜的情况
	{
		p6 = (PPlan)malloc(PLANSIZE);                                         //来实现当前蔬菜节点下没有种植计划时从无到有的添加plan
		p6->next = NULL;
		p5 = p6;
		p3->nextplan = p5;
	}
	p6 = p5->next;
	while (p6 != NULL)
	{
		p5 = p5->next;
		p6 = p6->next;
	}
	p5->PlanCode = ++hang3;														//向节点赋值
	p5->PlanVegCode = temp;
	p5->PlanArea = temparea;
	p5->PlanWeight = tempw;
	sprintf(p5->PlanYear, "%s", tempYear);
	p5->next=NULL;
	p6 = (PPlan)malloc(PLANSIZE);
	p6->next = NULL;
	p5->next = p6;
	printf("添加计划成功!Add Plan Successfully!\n");
	system("pause");

}



//实现修改计划，入口出口参数无。
void changePlan()
{
	PType p;
	PType p1;
	int i = 1;
	int temp;
	int temparea;
	float tempw;
	char tempYear[5];
	p1 = headv->nexttype;
	p = p1->nexttype;
	printf("请输入想要改变哪种蔬菜的种植信息（蔬菜编号int）\n");
	scanf("%d", &temp);
	getchar();
	printf("请输入想要改变这种蔬菜哪一年的种植信息（种植年份char[5]）\n");
	scanf("%s", tempYear);
	getchar();
	PInfo p3 = NULL, p4 = NULL;
	p3 = p1->nextinf;
	p4 = p3->nextinfo;
	while (p3->VegCode != temp)                                               //判定是否找到
	{
		p3 = p3->nextinfo;
		p4 = p4->nextinfo;
		if (p4 == NULL)                                                      //此信息链找完，换下一个种类对应的信息链
		{
			p1 = p1->nexttype;
			p3 = p1->nextinf;
			p4 = p3->nextinfo;
		}
	}
	PPlan p5, p6;
	p5 = p3->nextplan;
	p6 = p5->next;
	while (strcmp(p5->PlanYear,tempYear)!=0)                                   //判定是否找到
	{
		p5 = p5->next;
		p6 = p6->next;
	}
	printf("请输入改成的种植面积（int)\n");
	scanf("%d", &temparea);
	getchar();
	printf("请输入改成的收获重量（float)\n");
	scanf("%f", &tempw);
	getchar();
	printf("请输入改成的种植年份(char[5])\n");
	scanf("%s", tempYear);
	getchar();
	p5->PlanVegCode = temp;														//向节点赋值
	p5->PlanArea = temparea;
	p5->PlanWeight = tempw;
	sprintf(p5->PlanYear, "%s", tempYear);
	printf("修改完成！Successfully Changed！\n");
	system("pause");
}




//实现删除计划，入口出口参数无。
void deletePlan()
{
	PType p;
	PType p1;
	int i = 1;
	int temp;
	int temparea;
	float tempw;
	char tempYear[5];
	p1 = headv->nexttype;
	p = p1->nexttype;
	printf("请输入想要删除哪种蔬菜的种植信息（蔬菜编号int）\n");
	scanf("%d", &temp);
	getchar();
	printf("请输入想要删除这种蔬菜哪一年的种植信息（种植年份char[5]）\n");
	scanf("%s", tempYear);
	getchar();
	PInfo p3 = NULL, p4 = NULL;
	p3 = p1->nextinf;
	p4 = p3->nextinfo;
	while (p3->VegCode != temp)												//判定是否找到
	{
		p3 = p3->nextinfo;
		p4 = p4->nextinfo;
		if (p4 == NULL)                                                   //此信息链找完，换下一个种类对应的信息链
		{
			p1 = p1->nexttype;
			p3 = p1->nextinf;
			p4 = p3->nextinfo;
		}
	}
	PPlan p5, p6, pb=NULL;                                                 //pb用来表示前面那个,p5是当前的,p6是下一个，默认必定能找到，否则错误需要添加额外判断条件
	PInfo ptemp = NULL;
	ptemp = p3;
	p5 = p3->nextplan;
	p6 = p5->next;
	while (strcmp(p5->PlanYear, tempYear) != 0)								//判定是否找到
	{
		pb = p5;
		p5 = p5->next;
		p6 = p6->next;
	}
	if (pb == NULL)                                                       //pb==NULL此情况意味着此时p5计划节点为信息节点后跟的第一个计划节点，故pb此时不是p5的前一个计划节点而是信息节点
	{
		ptemp->nextplan = p6;
		p5->next = NULL;
	}
	else                                                                   //不为空即找到了计划链中的p5以及其前后节点
	{
		pb->next = p6;
		p5->next = NULL;
	}
	printf("删除完成！Successfully Deleted！\n");
	system("pause");
}




//实现按分类编码搜索，入口出口参数无。
void searchType(int temp)
{
	int n = 1;                                                           //用于输出type & info & plan各节点信息，注意最后一个别输出
	int i = 1; 
	int j = 1;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
    PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p->TypeCode != temp)
	{
		p = p->nexttype;
	}
	
	printf("分类编号：%d    分类名称：%s \n", p->TypeCode, p->TypeName);
    headi = p->nextinf;
    px = headi;
	while (px != NULL)
	{
		px = px->nextinfo;
		suminfo++;
	}
	px = headi;
    for(i=1;i<suminfo;i++)
    {
        printf("***分类码：%d   蔬菜编号：%d    名称：%s    营养成分：%s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
		pxx = px->nextplan;
		while (pxx != NULL)
		{
			pxx = pxx->next;
			sumplan++;
		}
		pxx = px->nextplan;
		for (j = 1; j < sumplan; j++)
		{
			printf("         ---蔬菜编号：%d   编号：%d   面积：%d   重量：%f   年份：%s \n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
			pxx = pxx->next;
		}
        px=px->nextinfo;
		sumplan = 0;
    }
	suminfo = 0;
    
	i = 1;
	n = 1;
	j = 1;

    system("pause");
}




//实现子串判定，入口参数为两个字符串，出口参数为一个字符指针。
char* isZich(char* s, char* t)                              //t为子串，s为串，返回不为空则是子串，空则不是字串
{
	int i, j, k = 0, slen, tlen;
	char* p = NULL;

	slen = strlen(s);
	tlen = strlen(t);
	for (i = 0; i < slen; i++) {
		j = i;
		while (s[j] == t[k]) 
		{
			k++;
			j++;
		}
		if (k >= tlen) 
		{
			p = &s[i];
			return p;
		}
		k = 0;
	}
	return p;
}





//实现按分类编码搜索，入口出口参数无。
void searchZich()
{
	printf("请输入想要查询哪类蔬菜中以及名称子串（char[8] char[6])\n");
	char tempty[8];
	char tempzi[8];
	char tempName[8];
	scanf("%s", tempty);
	scanf("%s", tempzi);
	int n = 1;                                //用于输出type & info & plan各节点信息，注意最后一个别输出
	int i = 1;
	int j = 1;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
	PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (strcmp(p->TypeName,tempty)!=0)
	{
		p = p->nexttype;
	}
	printf("分类编号：%d    分类名称：%s \n", p->TypeCode, p->TypeName);
	headi = p->nextinf;
	px = headi;
	while (px != NULL)
	{
		px = px->nextinfo;
		suminfo++;
	}
	px = headi;
	for (i = 1; i < suminfo; i++)
	{
		sprintf(tempName, "%s", px->VegName);
		char* po = isZich(tempName, tempzi);
		if (po!= NULL)
		{
			printf("***分类码：%d   蔬菜编号：%d    名称：%s    营养成分：%s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
			pxx = px->nextplan;
			while (pxx != NULL)
			{
				pxx = pxx->next;
				sumplan++;
			}
			pxx = px->nextplan;
			for (j = 1; j < sumplan; j++)
			{
				printf("         ---蔬菜编号：%d   编号：%d   面积：%d   重量：%f   年份：%s \n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
				pxx = pxx->next;
			}
		}
		px = px->nextinfo;
		sumplan = 0;
	}
	suminfo = 0;

	i = 1;
	n = 1;
	j = 1;

	system("pause");
}




//实现按分类码和营养子串搜索，入口出口参数无。
void searchFen()
{
	printf("请输入想要查询的分类码以及营养成分子串（int char[20])\n");
	int temp=0;
	char tempzi[20];
	char tempNu[50];
	scanf("%d", &temp);
	scanf("%s", tempzi);
	int n = 1;                                //用于输出type & info & plan各节点信息，注意最后一个别输出
	int i = 1;
	int j = 1;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
	PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p->TypeCode!=temp)
	{
		p = p->nexttype;
	}
	printf("分类编号：%d    分类名称：%s \n", p->TypeCode, p->TypeName);
	headi = p->nextinf;
	px = headi;
	while (px != NULL)
	{
		px = px->nextinfo;
		suminfo++;
	}
	px = headi;
	for (i = 1; i < suminfo; i++)
	{
		sprintf(tempNu, "%s", px->VegNutri);
		char* po = isZich(tempNu, tempzi);
		if (po != NULL)
		{
			printf("***分类码：%d   蔬菜编号：%d    名称：%s    营养成分：%s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
			pxx = px->nextplan;
			while (pxx != NULL)
			{
				pxx = pxx->next;
				sumplan++;
			}
			pxx = px->nextplan;
			for (j = 1; j < sumplan; j++)
			{
				printf("         ---蔬菜编号：%d   编号：%d   面积：%d   重量：%f   年份：%s \n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
				pxx = pxx->next;
			}
		}
		px = px->nextinfo;
		sumplan = 0;
	}
	suminfo = 0;

	i = 1;
	n = 1;
	j = 1;

	system("pause");
}




//实现按蔬菜子串以及年份搜索，入口出口参数无。
void searchYear()
{
	printf("请输入想要查询蔬菜名称子串以及年份（char[6] char[5] )\n");
	char tempzi[8];
	char tempName[8];
	char tempYear[5];
	scanf("%s", tempzi);
	scanf("%s", tempYear);
	int n = 1;                                //用于输出type & info & plan各节点信息，注意最后一个别输出
	int i = 1;
	int j = 1;
	int sumtype = 0;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
	PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p != NULL)
	{
		p = p->nexttype;
		sumtype++;
	}
	p = headv->nexttype;
	for (n = 1; n < sumtype; n++)
    {
		//printf("%d  %s\n", p->TypeCode, p->TypeName);
        headi = p->nextinf;
        px = headi;
		while (px != NULL)
		{
			px = px->nextinfo;
			suminfo++;
		}
		px = headi;
        for(i=1;i<suminfo;i++)
        {
			sprintf(tempName, "%s", px->VegName);
			char* po = isZich(tempName, tempzi);
			if (po != NULL)
			{
				printf("***分类码：%d   蔬菜编号：%d    名称：%s    营养成分：%s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
				pxx = px->nextplan;
				while (pxx != NULL)
				{
					pxx = pxx->next;
					sumplan++;
				}
				pxx = px->nextplan;
				for (j = 1; j < sumplan; j++)
				{
					if (strcmp(pxx->PlanYear, tempYear) == 0)
						printf("         ---蔬菜编号：%d   编号：%d   面积：%d   重量：%f   年份：%s \n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
					pxx = pxx->next;
				}
			}
            px=px->nextinfo;
			sumplan = 0;
        }
        p = p->nexttype;
		suminfo = 0;
    }
	i = 1;
	n = 1;
	j = 1;

    system("pause");
}




//实现按蔬菜名称搜索，入口出口参数无。
void searchName()
{
	printf("请输入想要查询蔬菜名称（char[8])\n");
	char tempName[8];
	scanf("%s", tempName);
	
	FILE* fp;
	if ((fp = fopen("按名称统计表.csv", "w+")) == NULL)         //保存蔬菜种类信息
		Failure();
	char a2[2] = "\n\0";
	char b1[5] = "年份\0";
	char b2[9] = "蔬菜名称\0";
	char b3[9] = "分类名称\0";
	char b4[9] = "种植面积\0";
	char b5[9] = "收获重量\0";
	fprintf(fp, "%s,%s,%s,%s,%s", b1, b2, b3, b4, b5);
	fprintf(fp, "%s", a2);
	
	
	int n = 1;                                //用于输出type & info & plan各节点信息，注意最后一个别输出
	int i = 1;
	int j = 1;
	int sumtype = 0;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
	PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p != NULL)
	{
		p = p->nexttype;
		sumtype++;
	}
	p = headv->nexttype;
	for (n = 1; n < sumtype; n++)
	{
		//printf("%d  %s\n", p->TypeCode, p->TypeName);
		headi = p->nextinf;
		px = headi;
		while (px != NULL)
		{
			px = px->nextinfo;
			suminfo++;
		}
		px = headi;
		for (i = 1; i < suminfo; i++)
		{
			if (strcmp(px->VegName, tempName) == 0)
			{
				printf("***分类码：%d   蔬菜编号：%d    名称：%s    营养成分：%s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
				pxx = px->nextplan;
				while (pxx != NULL)
				{
					pxx = pxx->next;
					sumplan++;
				}
				pxx = px->nextplan;
				for (j = 1; j < sumplan; j++)
				{
					printf("         ---蔬菜编号：%d   编号：%d   面积：%d   重量：%f   年份：%s \n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
					
					fprintf(fp, "%s,%s,%s,%d,%f", pxx->PlanYear, px->VegName,p->TypeName, pxx->PlanArea, pxx->PlanWeight);
					fprintf(fp, "%s", a2);
													            //自动导出生成新文件，完成要求的第一个按名称统计表
					pxx = pxx->next;
				}
			}
			px = px->nextinfo;
			sumplan = 0;
		}
		p = p->nexttype;
		suminfo = 0;
	}
	i = 1;
	n = 1;
	j = 1;


	printf("\n\n");                                            //自动导出生成新文件,完成要求的第一个
	printf("此蔬菜的种植信息已经导出至按名称统计表.csv\n\n");
	
	
	fclose(fp);
	fp = NULL;

	system("pause");
}




//实现统计某类蔬菜中已有的蔬菜数量，入口参数为整型实数，代表哪一类蔬菜，出口参数无。
void countSum(int temp)
{
	int n = 1;													//用于输出type & info & plan各节点信息，注意最后一个别输出
	int i = 1;
	int j = 1;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
	PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p->TypeCode != temp)
	{
		p = p->nexttype;
	}

	printf("分类编号：%d    分类名称：%s \n", p->TypeCode, p->TypeName);
	headi = p->nextinf;
	px = headi;
	while (px != NULL)
	{
		px = px->nextinfo;
		suminfo++;
	}
	px = headi;
	printf("当前种类下已有的蔬菜数量为：%d  \n", suminfo-1);
	system("pause");
}




//实现统计含有某营养成分的蔬菜信息并显示，入口参数为字符指针，指向营养成分子串，出口参数无。
void countNu(char* s)
{
	int n = 1;                                //用于输出type & info & plan各节点信息，注意最后一个别输出
	int i = 1; int j = 1;
	int sumtype = 0;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
    PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p != NULL)
	{
		p = p->nexttype;
		sumtype++;
	}
	p = headv->nexttype;
	for (n = 1; n < sumtype; n++)
    {
		//printf("%d  %s\n", p->TypeCode, p->TypeName);
        headi = p->nextinf;
        px = headi;
		while (px != NULL)
		{
			px = px->nextinfo;
			suminfo++;
		}
		px = headi;
        for(i=1;i<suminfo;i++)
        {
			char tempNu[50];
			sprintf(tempNu, "%s", px->VegNutri);
			char* po = isZich(tempNu, s);
			if (po != NULL)
				printf("%s\n", px->VegName);
            px=px->nextinfo;
        }
        p = p->nexttype;
		suminfo = 0;
    }
	i = 1;
	n = 1;
	j = 1;
    system("pause");
}




//实现统计某一年各类蔬菜信息并按收获重量降序排序后显示以及输出柱状统计图，入口出口参数无
void count1Year()
{
	char year[5];
	scanf("%s", year);
	struct temp {
		float weight;
		char typeName[8];
		int area;
	}temp[10], zancun;
	int i = 1; int j = 1;
	for (i = 1; i < 10; i++)                  //从1开始使用，0弃掉不用
	{
		temp[i].weight = 0;
		temp[i].area = 0;                     //typeName未初始化，不以他作为判定条件
	}
	int n = 1;                                //用于输出type & info & plan各节点信息，注意最后一个别输出
	i = 1; j = 1;
	int k = 1;
	int flag = 0;                             //用来标记是否进行对temp数组赋值，即用来判断是否k增加
	int sumtype = 0;
	int suminfo = 0;
	int sumplan = 0;
	int sum = 0;
	PType p;
	PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p != NULL)
	{
		p = p->nexttype;
		sumtype++;
	}
	p = headv->nexttype;
	for (n = 1; n < sumtype; n++)
	{
		//printf("%d  %s\n", p->TypeCode, p->TypeName);
		headi = p->nextinf;
		px = headi;
		while (px != NULL)
		{
			px = px->nextinfo;
			suminfo++;
		}
		px = headi;
		for (i = 1; i < suminfo; i++)
		{
			//printf("%d  %d  %s  %s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
			pxx = px->nextplan;
			while (pxx != NULL)
			{
				pxx = pxx->next;
				sumplan++;
			}
			pxx = px->nextplan;
			for (j = 1; j < sumplan; j++)
			{
				if ((strcmp(year, pxx->PlanYear) == 0))
				{
					temp[k].weight += pxx->PlanWeight;
					temp[k].area += pxx->PlanArea;
					sprintf(temp[k].typeName, "%s", p->TypeName);
					flag = 1;
				}
				pxx = pxx->next;
				
			}
			px = px->nextinfo;
			sumplan = 0;
			if (((i + 1) >= suminfo) && flag == 1)
			{
				k++;                         //同一种蔬菜下的计划累加，分别用不同下标的结构数组存储
				flag = 0;
			}
		}
		p = p->nexttype;
		suminfo = 0;
	}
	i = 1;
	n = 1;
	j = 1;
	float tweight;
	for (i = 1; i < 10; i++)
	{
		if (temp[i].area != 0)
			sum++;                          //共有几个有效，从一开始
	}

	for (i = 1; i <= sum; i++)              //降序
	{
		for (j = 1; j <= sum - i; j++)
		{
			if (temp[j + 1].weight > temp[j].weight)
			{
				zancun = temp[j + 1];
				temp[j + 1] = temp[j];
				temp[j] = zancun;           //如果a[j + 1]>a[j],则把这两个数组元素互换，目的把最大的数放到前边；
			}
			else
			{
				continue;
			}
		}
	}

	for (i = 1; i <= sum; i++)
	{
		printf("所属种类：%s    总面积：%d    总重量：%f\n",  temp[i].typeName, temp[i].area, temp[i].weight);
	}

	i = 1; j = 1;
	printf("\n\n");
	for (i = 10; i >= 1; i--)
	{
		//printf("|\n");
		printf("%d -   ",10*i);
		for (j = 1; j <= sum; j++)
		{
			if (temp[j].weight >= (10 * i))
				printf("#####     ");
		}
		printf("\n");
	}
	printf(" 0 ------------------------------------------------------------------->");


	printf("\n\n");                                            //自动导出生成新文件,完成要求的第二个按年份统计表
	printf("此年的蔬菜种植信息已经导出至按年份统计表.csv\n\n");
	FILE* fp;
	if ((fp = fopen("按年份统计表.csv", "w+")) == NULL)         //保存蔬菜种类信息
		Failure();
	char a2[2] = "\n\0";
	char b1[5] = "年份\0";
	char b2[9] = "分类名称\0";
	char b3[9] = "种植面积\0";
	char b4[11] = "收获总重量\0";
	fprintf(fp, "%s,%s,%s,%s", b1, b2, b3, b4);
	fprintf(fp, "%s", a2);
	for (i = 1; i <= sum; i++)
	{
		fprintf(fp, "%s,%s,%d,%f", year, temp[i].typeName, temp[i].area, temp[i].weight);
		fprintf(fp, "%s", a2);
	}
	fclose(fp);
	fp = NULL;
	system("pause");
}




//实现统计起止年份间某蔬菜信息并按收获重量降序排序后显示，入口出口参数无
void count2Years()
{
	struct temp {
		float weight;
		char VegName[8];
		char typeName[8];
		int area;
	}temp[20],zancun;
	int i = 1; int j = 1;
	for (i = 1; i < 20; i++)                  //从1开始使用，0弃掉不用
	{
		temp[i].weight = 0;
		temp[i].area = 0;                     //vegName、typeName未初始化，不以他作为判定条件
	}
	char qi[5];
	char zhi[5];
	scanf("%s", qi);
	scanf("%s", zhi);
	int n = 1;                                //用于输出type & info & plan各节点信息，注意最后一个别输出
	i = 1;j = 1;
	int k = 1;
	int flag = 0;                             //用来标记是否进行对temp数组赋值，即用来判断是否k增加
	int sumtype = 0;
	int suminfo = 0;
	int sumplan = 0;
	int sum = 0;
	PType p;
    PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p != NULL)
	{
		p = p->nexttype;
		sumtype++;
	}
	p = headv->nexttype;
	for (n = 1; n < sumtype; n++)
    {
		//printf("%d  %s\n", p->TypeCode, p->TypeName);
        headi = p->nextinf;
        px = headi;
		while (px != NULL)
		{
			px = px->nextinfo;
			suminfo++;
		}
		px = headi;
        for(i=1;i<suminfo;i++)
        {
            //printf("%d  %d  %s  %s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
			pxx = px->nextplan;
			while (pxx != NULL)
			{
				pxx = pxx->next;
				sumplan++;
			}
			pxx = px->nextplan;
			for (j = 1; j < sumplan;j++)
			{
				if ((strcmp(qi, pxx->PlanYear) <= 0) && (strcmp(pxx->PlanYear, zhi) <= 0))
				{
					//printf("              %d %d %d %f %s\n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
					temp[k].weight += pxx->PlanWeight;
					temp[k].area += pxx->PlanArea;
					sprintf(temp[k].VegName, "%s", px->VegName);
					sprintf(temp[k].typeName, "%s", p->TypeName);
					flag = 1;
				}
				pxx = pxx->next;
				if (((j + 1) >= sumplan) && flag == 1)
				{
					k++;                     //同一种蔬菜下的计划累加，分别用不同下标的结构数组存储
					flag = 0;
				}
			}
            px=px->nextinfo;
			sumplan = 0;
        }
        p = p->nexttype;
		suminfo = 0;
    }
	i = 1;
	n = 1;
	j = 1;
	float tweight;
	for (i = 1; i < 20; i++)
	{
		if (temp[i].area != 0)
			sum++;                          //共有几个有效，从一开始
	}

	for (i = 1; i <=sum; i++)             //降序
	{
		for (j =1; j <=sum-i; j++)       
		{
			if (temp[j + 1].weight > temp[j].weight)
			{
				zancun = temp[j + 1];
				temp[j + 1] = temp[j];
				temp[j] = zancun;           //如果a[j + 1]>a[j],则把这两个数组元素互换，目的把最大的数放到前边；
			}
			else
			{
				continue;
			}
		}
	}
	for (i = 1; i <= sum; i++)
	{
		printf("蔬菜名称：%s    所属种类：%s    总面积：%d    总重量：%f\n", temp[i].VegName, temp[i].typeName, temp[i].area, temp[i].weight);
	}

    system("pause");
}




//（便于检查直观，实现在屏幕上打印当前所有系统中的信息，入口出口参数无
void printData()
{
	int n = 1;                                //用于输出type & info & plan各节点信息，注意最后一个别输出
	int i = 1; int j = 1;
	int sumtype = 0;
	int suminfo = 0;
	int sumplan = 0;
	PType p;
    PInfo px;
	PPlan pxx;
	p = headv->nexttype;
	while (p != NULL)
	{
		p = p->nexttype;
		sumtype++;
	}
	p = headv->nexttype;
	for (n = 1; n < sumtype; n++)
    {
		printf("分类编号：%d    分类名称：%s\n", p->TypeCode, p->TypeName);
        headi = p->nextinf;
        px = headi;
		while (px != NULL)
		{
			px = px->nextinfo;
			suminfo++;
		}
		px = headi;
        for(i=1;i<suminfo;i++)
        {
            printf("*****分类码：%d    蔬菜编号：%d    蔬菜名称：%s    营养成分：%s  \n", px->VegType, px->VegCode, px->VegName, px->VegNutri);
			pxx = px->nextplan;
			while (pxx != NULL)
			{
				pxx = pxx->next;
				sumplan++;
			}
			pxx = px->nextplan;
			for (j = 1; j < sumplan; j++)
			{
				printf("             ----- 编码：%d   蔬菜编号：%d   面积：%d    收获重量：%f    年份：%s  \n", pxx->PlanVegCode, pxx->PlanCode, pxx->PlanArea, pxx->PlanWeight, pxx->PlanYear);
				pxx = pxx->next;
			}
            px=px->nextinfo;
			sumplan = 0;
        }
        p = p->nexttype;
		suminfo = 0;
    }
	i = 1;
	n = 1;
	j = 1;

    system("pause");


}




//实现保存、导出所有系统中的信息到当一开始加载的文件中，入口出口参数无
void save()
{
	PType p;
	PType p1;
	FILE* fp;
	if ((fp = fopen("蔬菜种类.csv", "w+")) == NULL)         //保存蔬菜种类信息
		Failure();
	char delims[] = ",";
	char* line, * record;
	char buffer[1024];
	int i = 1, j = 1;
	char a1[9] = "分类编号\0";
	fprintf(fp, "%s", a1);
	p1 = headv->nexttype;                                   //p1指向当前，p指向下一个
	p = p1->nexttype;
	while (p != NULL)
	{
		fprintf(fp, ",%d", p1->TypeCode);
		p1 = p1->nexttype;
		p = p->nexttype;
	}
	char a2[2] = "\n\0";
	fprintf(fp, "%s", a2);
	char a3[9] = "分类名称\0";
	fprintf(fp, "%s", a3);
	p1 = headv->nexttype;
	p = p1->nexttype;
	while (p != NULL)
	{
		fprintf(fp, ",%s", p1->TypeName);
		p1 = p1->nexttype;
		p = p->nexttype;
	}
	fprintf(fp, "%s", a2);
	p1 = headv->nexttype;
	p = p1->nexttype;
	fclose(fp);
	fp = NULL;


	FILE* fp2;
	if ((fp2 = fopen("蔬菜信息.csv", "w+")) == NULL)         //写入蔬菜种类信息
		Failure();
	i = 1; j = 1;
	int flag = 0;
	char b1[9] = "蔬菜编号\0";
	char b2[9] = "蔬菜名称\0";
	char b3[7] = "分类码\0";
	char b4[9] = "营养成分\0";
	fprintf(fp2, "%s,%s,%s,%s", b1,b2,b3,b4);
	fprintf(fp2, "%s", a2);
	p1 = headv->nexttype;
	p = p1->nexttype;
	PInfo p3 = NULL, p4 = NULL;
	p3 = p1->nextinf;
	p4 = p3->nextinfo;
	while (i != (hang2+1))
	{
		while ((p3->VegCode != i))
		{
			if (p4 != NULL)
			{
				p3 = p3->nextinfo;
				p4 = p4->nextinfo;
			}
			if (p4 == NULL)
			{
				p1 = p1->nexttype;
				if (p1->nexttype == NULL)
				{
					flag = 1;
					break;
				}
				p3 = p1->nextinf;
				p4 = p3->nextinfo;
			}
		}
		if (flag == 1)
		{
			i++;
			p1 = headv->nexttype;
			p = p1->nexttype;
			p3 = p1->nextinf;
			p4 = p3->nextinfo;
			flag = 0;
			continue;
		}
		fprintf(fp2, "%d,%s,%d,%s", p3->VegCode,p3->VegName,p3->VegType,p3->VegNutri);
		fprintf(fp2, "%s", a2);
		i++;
		p1 = headv->nexttype;
		p = p1->nexttype;
		p3 = p1->nextinf;
		p4 = p3->nextinfo;
    }
	p1 = headv->nexttype;
	p = p1->nexttype;
	fclose(fp2);
	fp2 = NULL;


	FILE* fp3;
	if ((fp3 = fopen("种植信息.csv", "w+")) == NULL)         //写入种植计划信息
		Failure();
	i = 1; j = 1; flag = 0;
	char c1[5] = "编号\0";
	char c2[9] = "蔬菜编号\0";
	char c3[9] = "种植面积\0";
	char c4[9] = "收获重量\0";
	char c5[9] = "种植年份\0";
	fprintf(fp3, "%s,%s,%s,%s,%s", c1, c2, c3, c4,c5);
	fprintf(fp3, "%s", a2);
	p1 = headv->nexttype;
	p = p1->nexttype;
	p3 = NULL, p4 = NULL;
	PPlan p5 = NULL, p6 = NULL;
	p3 = p1->nextinf;
	p4 = p3->nextinfo;
	p5 = p3->nextplan;
	p6 = p5->next;
	while (i != (hang3 + 1))
	{
		while ((p5->PlanCode != i))
		{
			if (p6 != NULL)                             //防止此时p5已经指向最后一个无意义节点且p6已为NULL
			{
				p5 = p5->next;
				p6 = p6->next;
			}
			if (p6 == NULL)
			{
				p3 = p3->nextinfo;
				p4 = p4->nextinfo;
				p5 = p3->nextplan;
				if(p5!=NULL)
					p6 = p5->next;                      //防止在p5为NULL时仍向后面找导致错误
			}
			if (p4 == NULL)                             //p4为空说明此信息链寻找完毕
			{
		Label:	p1 = p1->nexttype;
				if (p1->nexttype == NULL)               //flag==1说明全部找完也没找到plancode为i的种植计划
				{
					flag = 1;
					break;
				}
				p3 = p1->nextinf;
				p4 = p3->nextinfo;
				p5 = p3->nextplan;
				if(p5!=NULL)
					p6 = p5->next;
				while(p5 == NULL)                           //可能这种蔬菜没有已输入的计划，一直找到一个有计划的蔬菜的基本信息
				{
					p3 = p3->nextinfo;
					p4 = p4->nextinfo;
					p5 = p3->nextplan;
					if (p5 != NULL)
						p6 = p5->next;                      //防止在p5为NULL时仍向后面找导致错误
					if (p4 == NULL)
					{
						goto Label;                         //为求方便使用一次goto来在当前基本信息链搜索完毕后跳转到下一个种类节点对应的下一条信息链，也可以通过循环和flag搭配实现此功能
					}
				}
			}
		}
		if (flag == 1)
		{
			i++;
			p1 = headv->nexttype;
			p = p1->nexttype;
			p3 = p1->nextinf;
			p4 = p3->nextinfo;
			p5 = p3->nextplan;
			p6 = p5->next;
			flag = 0;
			continue;
		}
		fprintf(fp3, "%d,%d,%d,%f,%s", p5->PlanCode, p5->PlanVegCode, p5->PlanArea, p5->PlanWeight,p5->PlanYear);
		fprintf(fp3, "%s", a2);
		i++;
		p1 = headv->nexttype;
		p = p1->nexttype;
		p3 = p1->nextinf;
		p4 = p3->nextinfo;
		p5 = p3->nextplan;
		p6 = p5->next;
	}
	p1 = headv->nexttype;
	p = p1->nexttype;
	fclose(fp3);
	fp3 = NULL;


}
