#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define ENTER 13
#define BKSP 8
#define SPACE 32
#define TAB 9

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
//	SetConsoleTextAttributes(hStdOut,wColor);
	SetConsoleTextAttribute(hStdOut,wColor);

}
}


struct item
{
	char productname[40],productcomp[40],c;
	int productid;
	int price;
	int Qnt;
	char buyername[40];
	char month[40];
	int date;
	int code;
	int amount ;
	char employeename[40];
	char position[40];
	int age ;
	int idno;
	int salary ;
}st;


void wel_come(void);
void title(void);
void login();
void menu(void);
void title(void);
void deleteproduct(void);
void gotoxy(short x, short y)
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void AddProduct(void);
void CheckStock(void);
void ViewSearchProduct(void);
void EditProduct(void);
void AddEmployees(void);
void ViewEmployeesDetails(void);
void AddBuyersNameandDate(void);
void ViewBuyersNameandDate(void);
void ViewCalculatesBill(void);
void Replacement(void);
void ViewDeleteProducts(void);
void EditEmployees(void);
void DeleteEmployees(void);


void main(void)

{
wel_come(); //call for welcome screen function
login(); //call for login function
}


void wel_come(void)

{
	time_t t;
	time(&t);
    printf("\t\t\t\t\t     |   *              /\\        ----------------------       /\\                                    \n");
    printf("\t\t\t\t\t     |     *           /  \\                 |                 /  \\                                   \n");
    printf("\t\t\t\t\t     |       *        /    \\                |                /    \\                                  \n");
    printf("\t\t\t\t\t     |      *        /      \\               |               /      \\                                 \n");
    printf("\t\t\t\t\t     |   *          /        \\              |              /        \\                                \n");
    printf("\t\t\t\t\t     |   *         ------------             |             ------------                               \n");
    printf("\t\t\t\t\t     |     *      /            \\            |            /            \\                              \n");
    printf("\t\t\t\t\t     |       *   /              \\           |           /              \\                             \n");
    printf("\t\t\t\t\t     |      *   /                \\          |          /                \\                            \n");
    printf("\t\t\t\t\t     |   *     /                  \\         |         /                  \\                           \n");

	printf("\t\t\t\t                                                                                                         \n");
	printf("\t\t\t\t      -----------------------------------------------------------------------------------\n");
	printf("\t\t\t\t      \xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\t\t\t\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\t\t\t\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\t\t\t\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\t\t\t\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\t\t\t\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\xbd\t     WELCOME TO \t \xbd\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\xbd\t       BATA\t         \xbd\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t          Contact Info      \t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t      \"Jamuna Future Park\"\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t        \"Shop no-345(A)\"  \t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t   \"Mobile no-01882400479\"\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t \"Email-bata123@gmail.com\"\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\t\t\t\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\t\t\t\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\t\t\t\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\t\t\t\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\t\t\t\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\t\t\t\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\t\t\t\t\t\t\t\t\t\t\t\t\xbd\n");
	printf("\t\t\t\t      \xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\n");
		printf("\t\t\t\t\t\t\t\t %s",ctime(&t));
	printf("\t\t\t\t      \xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\xbd\n");
	printf("\n\t\t\t\t\t\t\t      Press any key to continue.........\t\t\t\t\t\t\t\t\t\t\n");

getch();
system("cls");
}

void login()
{
    printf("\t\t\t\t\t     |   *              /\\        ----------------------       /\\                                    \n");
    printf("\t\t\t\t\t     |     *           /  \\                 |                 /  \\                                   \n");
    printf("\t\t\t\t\t     |       *        /    \\                |                /    \\                                  \n");
    printf("\t\t\t\t\t     |      *        /      \\               |               /      \\                                 \n");
    printf("\t\t\t\t\t     |   *          /        \\              |              /        \\                                \n");
    printf("\t\t\t\t\t     |   *         ------------             |             ------------                               \n");
    printf("\t\t\t\t\t     |     *      /            \\            |            /            \\                              \n");
    printf("\t\t\t\t\t     |       *   /              \\           |           /              \\                             \n");
    printf("\t\t\t\t\t     |      *   /                \\          |          /                \\                            \n");
    printf("\t\t\t\t\t     |   *     /                  \\         |         /                  \\                           \n");


int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n\t\t\t\t\t\t  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb LOGIN \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  ");
    printf(" \n\t\t\t\t\t\t                        USERNAME:-");
	scanf("%s", &uname);
	printf(" \n\t\t\t\t\t\t                        PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"BATA")==0 && strcmp(pword,"BATA")==0)
	{
	printf("  \n\n\n\t\t\t\t\t       WELCOME TO BATA STORE MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\t\t\t\t\t\t\t     SYSTEM IS LOADING. PLEASE WAIT... \n");
    for(i=0; i<3; i++)
    {
        printf(".");
        Sleep(500);
    }
	printf("\n\n\n\t\t\t\t\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n\t\t\t\t\t\t\t        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
		menu();
}



void menu(void)
{
	int choice;
	system("cls");
	main:
	printf("\t\t\t\t\t       |   *              /\\        ----------------------       /\\                                    \n");
    printf("\t\t\t\t\t       |     *           /  \\                 |                 /  \\                                   \n");
    printf("\t\t\t\t\t       |       *        /    \\                |                /    \\                                  \n");
    printf("\t\t\t\t\t       |      *        /      \\               |               /      \\                                 \n");
    printf("\t\t\t\t\t       |   *          /        \\              |              /        \\                                \n");
    printf("\t\t\t\t\t       |   *         ------------             |             ------------                               \n");
    printf("\t\t\t\t\t       |     *      /            \\            |            /            \\                              \n");
    printf("\t\t\t\t\t       |       *   /              \\           |           /              \\                             \n");
    printf("\t\t\t\t\t       |      *   /                \\          |          /                \\                            \n");
    printf("\t\t\t\t\t       |   *     /                  \\         |         /                  \\                           \n");

    printf("\n\t\t\t\t\t\t\t\t\t 1. Add Product");
    printf("\n\n\t\t\t\t\t\t\t\t\t 2. Check Stock");
    printf("\n\n\t\t\t\t\t\t\t\t\t 3. Search Product");
    printf("\n\n\t\t\t\t\t\t\t\t\t 4. Replacement");
    printf("\n\n\t\t\t\t\t\t\t\t\t 5. Add Employees");
    printf("\n\n\t\t\t\t\t\t\t\t\t 6. View Employees Details");
    printf("\n\n\t\t\t\t\t\t\t\t\t 7. Add Buyers Name and Date");
    printf("\n\n\t\t\t\t\t\t\t\t\t 8. View Buyers Name and Date");
    printf("\n\n\t\t\t\t\t\t\t\t\t 9. Calculate Bill");
    printf("\n\n\t\t\t\t\t\t\t\t\t10. Delete Products");
    printf("\n\n\t\t\t\t\t\t\t\t\t11. Edit Employees");
    printf("\n\n\t\t\t\t\t\t\t\t\t12. Remove Employees");
    printf("\n\n\t\t\t\t\t\t\t\t\t13. Exit");

	printf("\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice[1-13]");
	scanf("%i", &choice);

	system("cls");

	switch(choice)
	{

            case 1: AddProduct();
                    break;

            case 2: CheckStock();
                     break;

            case 3: ViewSearchProduct();
                    break;

            case 4: Replacement();
                    break;

            case 5: AddEmployees();
                    break;

            case 6: ViewEmployeesDetails();
                    break;

            case 7: AddBuyersNameandDate();
                     break;

            case 8: ViewBuyersNameandDate();
                     break;

            case 9: ViewCalculatesBill();
                     break;

            case 10: ViewDeleteProducts();
                     break;

            case 11: EditEmployees();
                     break ;

            case 12:DeleteEmployees();
                     break;

            case 13: printf("\n\n\t\t\t\t\t\t\t\t  Thank you\n\t\t\t\t\t\t\tPlease press any key for exit\n\n ");
                     break;


		default:
		printf("Invalid Choice! System Exit\n");
			getch();
			menu();
	}

}



void AddProduct()
{

	int index, valid;
	char c;
	int a=0;

	FILE *fp;


	do
	{
		system("cls");
		printf("\t\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Enter Item Details \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
		int ID;//for comparing staff ID if file isnot NULL
		//declaration of file variable named as sfile
		fp = fopen("BATA.txt","a+");//opening file and creating a staff.txt file to append or write

		if((fp = fopen("BATA.txt","a+"))!=NULL)//if condition to check file is NULL or not
		{
			I:
			printf("\n\t\t\t\t\t\t\t\tItem Code\t\t\t :");
			scanf("%i",&ID);
			while(fscanf(fp,"%s %s %i %i %i", st.productname, st.productcomp, &st.price, &st.productid,&st.Qnt)!=EOF)
			{
				/*
				fscanf reads every data stored in the file
				if entered staffID already exist then jumps to
				position I declared inside if(sfile!=NULL) at top
				*/
				if(ID == st.productid)
				{
					printf("\n\t\t\t\t\t\t\t\tTHE ITEM CODE ALREADY EXIST.\n");
					goto I;
				}
			}
			st.productid = ID;
		}
		else//runs if sfile is empty
		{
			printf("\nProduct Code\t\t\t  :");
			scanf("%i",&st.productid);
		}

	//add product name
		do
		{

			//printf("<<<<<<<<<<<<<<Enter Product Detail>>>>>>>>>>>>>");
			fflush(stdin);

			printf("\n\t\t\t\t\t\t\t\tItem Name\t\t\t :");
			gets(st.productname); // get input string
			st.productname[0]=toupper(st.productname[0]);
			//iterate for every character in string
			for (index=0; index<strlen(st.productname); ++index)
			{	//check if character is valid or not
				if(isalpha(st.productname[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n\t\t\t\t\t\t\t\t Name contain invalid character. Please 'Enter' again");
				getch();


			}
		}while(!valid);	//while end here


		//Product Company
			do
		{
			char productcomp[40];
			fflush(stdin);
			printf("\n\t\t\t\t\t\t\t\tItem Brand\t\t\t :");
			gets(st.productcomp); // get input string
			st.productcomp[0]=toupper(st.productcomp[0]);
			//iterate for every character in string
			for (index=0; index<strlen(st.productcomp); ++index)
			{	//check if character is valid or not
				if(isalpha(st.productcomp[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n\t\t\t\t\t\t\t\t Name contain invalid character. Please 'Enter' again");
				getch();


			}
		}while(!valid);

		//productid
		do
			{
				printf("\n\t\t\t\t\t\t\t\tPrice [10-50000]TK\t\t :");
				scanf("    %i",&st.price);
				if(st.price<10 || st.price>50000)
				{
					printf("\n\t\t\t\t\t\t\t\t\tYou Cannot Enter the price limit [10-50000].Re-Enter.");
				}
			}while(st.price<10 || st.price>50000);

				do
			{
				printf("\n\t\t\t\t\t\t\t\tQuantity [1-5000]\t\t :");
				scanf("%i",&st.Qnt);
				if(st.Qnt<1 || st.Qnt>5000)
				{
					printf("\n\t\t\t\t\t\t\t\t\tEnter Quantity[1-5000] only.Re-Enter.");
				}
			}while(st.Qnt<1 || st.Qnt>5000);

	//	printf("\nProduct Price\t :");
	//	scanf("%i", &st.price);
		//printf("\nProduct ID\t :");
		//scanf("%i", &st.productid);
	    //printf("\n\t\t\t\t\t\t\t\tProduct Quantity :");
        //scanf("%i",&st.Qnt);

		fp=fopen("BATA.txt","a");
		fprintf(fp,"\n%s %s %i %i %i", st.productname, st.productcomp,st.price, st.productid,st.Qnt);
		fclose(fp);
		 printf("\t\t\t\t\t\t\t\tEnter Any Key For Return");
	}
	while((c = getch()) =='\r');
	menu();
	}



	void CheckStock()
{
	FILE *f;
	int i, q;
	if((f=fopen("BATA.txt","r"))==NULL)
	{

		gotoxy(10,3);
		printf("NO RECORDS");
		printf("\nPress any key to go back to Menu.");
		getch();
		menu();


	}
	else
	{

		gotoxy(0,5);
			for(i=0;i<100;i++)
		{
			printf("\xdb");
		}
		gotoxy(5,6);
		printf("Item's Name");
		gotoxy(25,6);
		printf("Item's Price");
		gotoxy(40,6);
		printf("Item's Brand");
		gotoxy(60,6);
		printf("Item's CODE");
		gotoxy(80,6);
		printf("Item's Quantity\n");

		for(i=0;i<100;i++)
		{
			printf("\xdb");
		}
		q=8;
		while(fscanf(f,"%s %s %i %i %i\n", st.productname,st.productcomp, &st.price, &st.productid,&st.Qnt)!=EOF)
		{
			gotoxy(5,q);
			printf("%s",st.productname);
			gotoxy(25,q);
			printf("%i",st.price);
			gotoxy(40,q);
			printf("%s",st.productcomp);
			gotoxy(60,q);
			printf("%i",st.productid);
			gotoxy(80,q);
			printf("%i",st.Qnt);

			q++;
		}
		printf("\n");
		for(i=0;i<100;i++)
			printf("\xdb");
	}
	fclose(f);

	printf("\nPress any key to go to Main Menu!");
		//while((st.c = getch()) =='\r');
		getch();
		menu();
}




void ViewSearchProduct()
{
    char target[40];
	int found=0;
	FILE *sfile;
	sfile=fopen("BATA.txt","r");
	printf("\n\t\t\t\t\t\t\t\tEnter name to search:");
	fflush(stdin);
	gets(target);
	target[0]=toupper(target[0]);
	while (!feof(sfile) && found==0)
	{
		fscanf(sfile,"%s %s %i %i %i", st.productname, st.productcomp, &st.price, &st.productid,&st.Qnt);
		if(strcmp(target, st.productname)==0)
		{
			found=1;
		}
	}

	if(found)
	{
		printf("\n\t\t\t\t\t\t\t\tRecord found");
		printf("\n\t\t\t\t\t\t\t\tItem's Name\t\t:%s  \n\t\t\t\t\t\t\t\tItem's Brands\t\t:%s \n\t\t\t\t\t\t\t\tItem's Price\t\t:%i \n\t\t\t\t\t\t\t\tItem ID\t\t\t:%i \n\t\t\t\t\t\t\t\tItem Quantity\t\t:%i", st.productname, st.productcomp, st.price, st.productid, st.Qnt);

	}
	else
		printf("\t\t\t\t\t\t\t\tNoo Record found");
		fclose(sfile);
		printf("\n\t\t\t\t\t\t\t\tPress any key to go to Main Menu!");
		while((st.c = getch()) =='\r');
		menu();

}



void Replacement()
{
    int index, valid;
	char target[40];
	FILE *fp, *rp;
	int a=0;
	int id;
	char edit;
	long int size=sizeof(st);
	if((fp=fopen("BATA.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		menu();
	}
	else
	{
		rp = fopen("TempFile.dat","a");
		system("cls");
		printf("\t\t\t\t\t\t\t\tEnter Item's' Code for edit:");
		scanf("%i",&id);
		fflush(stdin);
		while(fscanf(fp,"%s %s %i %i %i\n", st.productname,st.productcomp, &st.price, &st.productid,&st.Qnt)!=EOF)
		{
			if(id==st.productid)
			{

				a=1;
				printf("\n\t\t\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb Record Found \xdb\xdb\xdb\xdb\xdb");
				printf("\n\t\t\t\t\t\t\t\tItem's Name\t\t: %s",st.productname);
				printf("\n\t\t\t\t\t\t\t\tItems's Brand\t\t: %s",st.productcomp);
				printf("\n\t\t\t\t\t\t\t\tPrice\t\t\t: %i",st.price);
				printf("\n\t\t\t\t\t\t\t\tItem's Code\t\t: %i",st.productid);
				printf("\n\t\t\t\t\t\t\t\tItem's Quantity\t:%i",st.Qnt);

				printf("\n\n\t\t\t\t\t\t\t\t\t*** New Record ***");
			do
				{

					fflush(stdin);
					printf("\n\t\t\t\t\t\t\t\tNew Item's Name\t\t: ");
					gets(st.productname); // get input string
					st.productname[0]=toupper(st.productname[0]);
					//iterate for every character in string
					for (index=0; index<strlen(st.productname); ++index)
					{	//check if character is valid or not
						if(isalpha(st.productname[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("\n Name contain invalid character. Please 'Enter' again");
						getch();


					}
				}while(!valid);	//while end here


				//Product Company
				do
				{
					char productcomp[40];
					fflush(stdin);
					printf("\n\t\t\t\t\t\t\t\tNew Item's Brand\t:");
					gets(st.productcomp); // get input string
					st.productcomp[0]=toupper(st.productcomp[0]);
					//iterate for every character in string
					for (index=0; index<strlen(st.productcomp); ++index)
					{	//check if character is valid or not
						if(isalpha(st.productcomp[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("\n Name contain invalid character. Please 'Enter' again");
						getch();


					}
				}while(!valid);

					do
			{
				printf("\n\t\t\t\t\t\t\t\tNew Price [10-50000]TK\t:");
				scanf("%i",&st.price);
				if(st.price<10 || st.price>50000)
				{
					printf("\n\tYou Cannot Enter the price limit [10-50000].Re-Enter.");
				}
			}while(st.price<10 || st.price>50000);

				printf("\n\t\t\t\t\t\t\t\tEnter New Item's Code\t:");
				scanf("%i",&st.productid);

				do
			{
				printf("\n\t\t\t\t\t\t\t\tNew Quantity [1-5000]\t:");
				scanf("%i",&st.Qnt);
				if(st.Qnt<1 || st.Qnt>5000)
				{
					printf("\n\t\t\t\t\t\t\t\t\tEnter New Quantity[1-5000] only.Re-Enter.");
				}
			}while(st.Qnt<1 || st.Qnt>5000);


				printf("\t\t\t\t\t\t\tPress 'y' to edit the existing record or any key to cancel...");
				edit=getche();
				if(edit=='y' || edit=='Y')
				{
					fprintf(rp,"%s %s %i %i %i\n", st.productname, st.productcomp, st.price, st.productid,st.Qnt);
					fflush(stdin);
					printf("\n\n\t\t\t\t\t\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
				}
			}
			else
			{
				fprintf(rp,"%s %s %i %i %i\n", st.productname, st.productcomp, st.price, st.productid,st.Qnt);
				fflush(stdin);
			}

		}
		if(!a)
		{
			printf("\n\nTHIS ITEM DOESN'T EXIST!!!!");
		}
		fclose(rp);
		fclose(fp);
		remove("BATA.txt");
		rename("TempFile.dat","BATA.txt");
		getch();
	}
	menu();


}



void AddEmployees()
{
    int index, valid;
	char c;
	int a=0;

	FILE *fp;


	do
	{
		system("cls");
		printf("\t\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Enter Employee Details \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
		int ID;//for comparing staff ID if file isnot NULL
		//declaration of file variable named as sfile
		fp = fopen("employee.txt","a+");//opening file and creating a staff.txt file to append or write

		if((fp = fopen("employee.txt","a+"))!=NULL)//if condition to check file is NULL or not
		{
			I:
			printf("\n\t\t\t\t\t\t\t\tEmployee ID\t\t   :");
			scanf("%i",&ID);
			while(fscanf(fp,"%s %s %i %i %i ", st.employeename, st.position, &st.age, &st.idno, &st.salary)!=EOF)
			{
				/*
				fscanf reads every data stored in the file
				if entered staffID already exist then jumps to
				position I declared inside if(sfile!=NULL) at top
				*/
				if(ID == st.idno)
				{
					printf("\n\t\t\t\t\t\t\t\tTHE EMPLOYEE ID ALREADY EXIST.\n");
					goto I;
				}
			}
			st.idno = ID;
		}
		else//runs if sfile is empty
		{
			printf("\nEmployee ID\t\t :");
			scanf("%i",&st.idno);
		}

	//add product name
		do
		{

			//printf("<<<<<<<<<<<<<<Enter Product Detail>>>>>>>>>>>>>");
			fflush(stdin);
			printf("\n\t\t\t\t\t\t\t\tEmployee Name\t\t   :");
			gets(st.employeename); // get input string
			st.employeename[0]=toupper(st.employeename[0]);
			//iterate for every character in string
			for (index=0; index<strlen(st.employeename); ++index)
			{	//check if character is valid or not
				if(isalpha(st.employeename[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n\t\t\t\t\t\t\t\tName contain invalid character. Please 'Enter' again");
				getch();


			}
		}while(!valid);	//while end here


		//Product Company
			do
		{
			char position[40];
			fflush(stdin);
			printf("\n\t\t\t\t\t\t\t\tPosition\t\t   :");
			gets(st.position); // get input string
			st.position[0]=toupper(st.position[0]);
			//iterate for every character in string
			for (index=0; index<strlen(st.position); ++index)
			{	//check if character is valid or not
				if(isalpha(st.position[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n\t\t\t\t\t\t\t\tName contain invalid character. Please 'Enter' again");
				getch();


			}
		}while(!valid);

		//ID
		do
			{
				printf("\n\t\t\t\t\t\t\t\tAge[25-45]\t\t   :");
				scanf("    %i",&st.age);
				if(st.age<25 || st.age>45)
				{
					printf("\n\t\t\t\t\t\t\t\tYou Cannot Enter the age limit [25-45].Re-Enter.");
				}
			}while(st.age<25 || st.age>45);

			do
			{
				printf("\n\t\t\t\t\t\t\t\tSalary [10000-50000]\t   :");
				scanf("%i",&st.salary);
				if(st.salary<10000 || st.salary>5000000)
				{
					printf("\n\tEnter Amount[10000-50000] only.Re-Enter.");
				}
			}while(st.salary<10000 || st.salary>50000);



		fp=fopen("employee.txt","a");
		fprintf(fp,"\n%s %s %i %i %i ", st.employeename, st.position,st.age, st.idno, st.salary);
		fclose(fp);
		printf("\t\t\t\t\t\t\t\tEnter Any Key For Return");

	}
	while((c = getch()) =='\r');
	menu();


}


void ViewEmployeesDetails()
{
    FILE *f;
	int i, q;
	if((f=fopen("employee.txt","r"))==NULL)
	{

		gotoxy(10,3);
		printf("NO RECORDS");
		printf("\nPress any key to go back to Menu.");
		getch();
		menu();


	}
	else
	{

		gotoxy(0,5);
			for(i=0;i<100;i++)
		{
			printf("\xdb");
		}
		gotoxy(5,6);
		printf("Employee Name");
		gotoxy(25,6);
		printf("Age");
		gotoxy(40,6);
		printf("Position");
		gotoxy(60,6);
		printf("ID\n");
		gotoxy(80,6);
		printf("Salary\n");


		for(i=0;i<100;i++)
		{
			printf("\xdb");
		}
		q=8;
		while(fscanf(f,"%s %s %i %i %i\n", st.employeename,st.position, &st.age, &st.idno, &st.salary)!=EOF)
		{
			gotoxy(5,q);
			printf("%s",st.employeename);
			gotoxy(25,q);
			printf("%i",st.age);
			gotoxy(40,q);
			printf("%s",st.position);
			gotoxy(60,q);
			printf("%i",st.idno);
			gotoxy(80,q);
			printf("%i",st.salary);
			q++;
		}
		printf("\n");
		for(i=0;i<100;i++)
			printf("\xdb");
	}
	fclose(f);

	printf("\nPress any key to go to Main Menu!");
		//while((st.c = getch()) =='\r');
		getch();
		menu();


}

void AddBuyersNameandDate()
{
    int index, valid;
	char c;
	int a=0;

	FILE *fp;


	do
	{
		system("cls");
		printf("\t\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Enter Buyer Details \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
		int ID;//for comparing staff ID if file isnot NULL
		//declaration of file variable named as sfile
		fp = fopen("Buyer.txt","a+");//opening file and creating a staff.txt file to append or write

		if((fp = fopen("Buyer.txt","a+"))!=NULL)//if condition to check file is NULL or not
		{
			I:
			printf("\n\t\t\t\t\t\t\t\tCode\t\t :");
			scanf("%i",&ID);
			while(fscanf(fp,"%s %s %i %i %i ", st.buyername, st.month, &st.date, &st.idno, &st.salary)!=EOF)
			{
				/*
				fscanf reads every data stored in the file
				if entered staffID already exist then jumps to
				position I declared inside if(sfile!=NULL) at top
				*/
				if(ID == st.code)
				{
					printf("\n\t\t\t\t\t\t\t\tTHE BUYER CODE ALREADY EXIST.\n");
					goto I;
				}
			}
			st.code = ID;
		}
		else//runs if sfile is empty
		{
			printf("\nBuyer Code\t :");
			scanf("%i",&st.code);
		}

	//add product name
		do
		{

			//printf("<<<<<<<<<<<<<<Enter Product Detail>>>>>>>>>>>>>");
			fflush(stdin);
			printf("\n\t\t\t\t\t\t\t\tBuyer Name\t :");
			gets(st.buyername); // get input string
			st.buyername[0]=toupper(st.buyername[0]);
			//iterate for every character in string
			for (index=0; index<strlen(st.buyername); ++index)
			{	//check if character is valid or not
				if(isalpha(st.buyername[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n\t\t\t\t\t\t\t\tName contain invalid character. Please 'Enter' again");
				getch();


			}
		}while(!valid);	//while end here


		//Product Company
			do
		{
			char month[40];
			fflush(stdin);
			printf("\n\t\t\t\t\t\t\t\tMonth\t\t :");
			gets(st.month); // get input string
			st.month[0]=toupper(st.month[0]);
			//iterate for every character in string
			for (index=0; index<strlen(st.month); ++index)
			{	//check if character is valid or not
				if(isalpha(st.month[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n\t\t\t\t\t\t\t\tName contain invalid character. Please 'Enter' again");
				getch();


			}
		}while(!valid);

		//code
		do
			{
				printf("\n\t\t\t\t\t\t\t\tDate[1-31]\t:");
				scanf("    %i",&st.date);
				if(st.date<1 || st.date>31)
				{
					printf("\n\t\t\t\t\t\t\t\tYou Cannot Enter the date limit [1-31].Re-Enter.");
				}
			}while(st.date<1 || st.date>31);

			do
			{
				printf("\n\t\t\t\t\t\t\t\tAmount [1-5000000]\t:");
				scanf("%i",&st.amount);
				if(st.amount<1 || st.amount>5000000)
				{
					printf("\n\tEnter Amount[1-5000000] only.Re-Enter.");
				}
			}while(st.amount<1 || st.amount>5000000);



		fp=fopen("Buyer.txt","a");
		fprintf(fp,"\n%s %s %i %i %i ", st.buyername, st.month,st.date, st.code, st.amount);
		fclose(fp);
		printf("\t\t\t\t\t\t\t\tEnter Any Key For Return");

	}
	while((c = getch()) =='\r');
	menu();

}



void ViewBuyersNameandDate()
{

    FILE *f;
	int i, q;
	if((f=fopen("Buyer.txt","r"))==NULL)
	{

		gotoxy(10,3);
		printf("NO RECORDS");
		printf("\nPress any key to go back to Menu.");
		getch();
		menu();


	}
	else
	{

		gotoxy(0,5);
			for(i=0;i<100;i++)
		{
			printf("\xdb");
		}
		gotoxy(5,6);
		printf("Name");
		gotoxy(25,6);
		printf("Date");
		gotoxy(40,6);
		printf("Month");
		gotoxy(60,6);
		printf("Code\n");
		gotoxy(80,6);
		printf("Amount\n");


		for(i=0;i<100;i++)
		{
			printf("\xdb");
		}
		q=8;
		while(fscanf(f,"%s %s %i %i %i\n", st.buyername,st.month, &st.date, &st.code, &st.amount)!=EOF)
		{
			gotoxy(5,q);
			printf("%s",st.buyername);
			gotoxy(25,q);
			printf("%i",st.date);
			gotoxy(40,q);
			printf("%s",st.month);
			gotoxy(60,q);
			printf("%i",st.code);
			gotoxy(80,q);
			printf("%i",st.amount);
			q++;
		}
		printf("\n");
		for(i=0;i<100;i++)
			printf("\xdb");
	}
	fclose(f);

	printf("\nPress any key to go to Main Menu!");
		//while((st.c = getch()) =='\r');
		getch();
		menu();

}




void ViewCalculatesBill()
{
  float discount_amount, tax_amount, discount, tax , Total_Amount;
    char Buyer_Name[70];
    int Saddle_Shoes , Boat_Shoes , Leather_Laced , Canvas_Shoes , Leather_Loafer , Sandals , Dress_Boots ,Rubber_Shoes , Heel , Formal , Sneaker , FlatShoes;
    int SUM1 , SUM2 , SUM3 , SUM4 , SUM5 , SUM6 , SUM7 , SUM8 ,SUM9 ,SUM10 , SUM11 , SUM12  ,Total , Sub_Total ;

    int Price_of_Saddle_Shoes = 4000;

    int Price_of_Boat_Shoes  = 6000;

    int Price_of_Leather_Laced = 7000 ;

    int Price_of_Canvas_Shoes = 1500 ;

    int Price_of_Leather_Loafer = 2000 ;

    int Price_of_Sandals = 700 ;

    int Price_of_Dress_Boots = 5000 ;

    int Price_of_Rubber_Shoes=700;

    int Price_of_Heel=3500;

    int Price_of_Formal=4000;

    int Price_of_Sneaker=2000;

    int Price_of_FlatShoes=1500;

  printf("\t\t\t\t\t\t\t\t\t\tBILL");
  printf("\n\t\t\t\t\t\t\tEnter Buyer Name                     : ");
  scanf("%s",&Buyer_Name);

  printf("\n\t\t\t\t\t\t\tEnter the quantity of Saddle Shoes   : ");
  scanf ("%d", &Saddle_Shoes) ;
  SUM1=Price_of_Saddle_Shoes*Saddle_Shoes;
  //printf("\n\t\t\t\t\t\t\tTotal amount of Saddle_Shoes : %d",SUM1);

  printf("\n\t\t\t\t\t\t\tEnter the quantity of Boat Shoes     : ");
  scanf ("%d", &Boat_Shoes) ;
  SUM2=Price_of_Boat_Shoes*Boat_Shoes;
  //printf("\n\t\t\t\t\t\t\tTotal amount of Boat_Shoes : %d",SUM2);

  printf("\n\t\t\t\t\t\t\tEnter the quantity of Leather Laced  : ");
  scanf ("%d", &Leather_Laced) ;
  SUM3=Price_of_Leather_Laced*Leather_Laced;
  //printf("\n\t\t\t\t\t\t\tTotal amount of Leather_Laced : %d",SUM3);

  printf("\n\t\t\t\t\t\t\tEnter the quantity of Canvas Shoes   : ");
  scanf ("%d", &Canvas_Shoes) ;
  SUM4=Price_of_Canvas_Shoes*Canvas_Shoes;
  //printf("\n\t\t\t\t\t\t\tTotal amount of Canvas_Shoes : %d",SUM4);

  printf("\n\t\t\t\t\t\t\tEnter the quantity of Leather Loafer : ");
  scanf ("%d", &Leather_Loafer) ;
  SUM5=Price_of_Leather_Loafer*Leather_Loafer;
  //printf("\n\t\t\t\t\t\t\tTotal amount of Leather_Loafer : %d",SUM5);

  printf("\n\t\t\t\t\t\t\tEnter the quantity of Sandals        : ");
  scanf ("%d", &Sandals) ;
  SUM6=Price_of_Sandals*Sandals;
  //printf("\n\t\t\t\t\t\t\tTotal amount of Sandals : %d",SUM6);

  printf("\n\t\t\t\t\t\t\tEnter the quantity of Dress Boots    : ");
  scanf ("%d", &Dress_Boots) ;
  SUM7=Price_of_Dress_Boots*Dress_Boots;
  //printf("\n\t\t\t\t\t\t\tTotal amount of Dress_Boots : %d",SUM7);

  printf("\n\t\t\t\t\t\t\tEnter the quantity of Rubber Shoes   : ");
  scanf ("%d", &Rubber_Shoes) ;
  SUM8=Price_of_Rubber_Shoes*Rubber_Shoes;
  //printf("\n\t\t\t\t\t\t\tTotal amount of Rubber_Shoes : %d",SUM8);

  printf("\n\t\t\t\t\t\t\tEnter the quantity of Heel           : ");
  scanf ("%d", &Heel) ;
  SUM9=Price_of_Heel*Heel;
  //printf("\n\t\t\t\t\t\t\tTotal amount of Heel : %d",SUM9);

  printf("\n\t\t\t\t\t\t\tEnter the quantity of Formal         : ");
  scanf ("%d", &Formal) ;
  SUM10=Price_of_Formal*Formal;
  //printf("\n\t\t\t\t\t\t\tTotal amount Formal : %d",SUM10);

  printf("\n\t\t\t\t\t\t\tEnter the quantity of Sneaker        : ");
  scanf ("%d", &Sneaker) ;
  SUM11=Price_of_Sneaker*Sneaker;
  //printf("\n\t\t\t\t\t\t\tTotal amount of Sneaker : %d",SUM11);

  printf("\n\t\t\t\t\t\t\tEnter the quantity of Flat Shoes     : ");
  scanf ("%d", &FlatShoes) ;
  SUM12=Price_of_FlatShoes*FlatShoes;
  //printf("\n\t\t\t\t\t\t\tTotal amount of Rubber_Shoes : %d",SUM12);

  Total=SUM1+SUM2+SUM3+SUM4+SUM5+SUM6+SUM7+SUM8+SUM9+SUM10+SUM11+SUM12;
  //printf("\n\t\t\t\t\t\t\tTotal_Amount                         :%d",Total);

   printf("\n\t\t\t\t\t\t\tEnter the discount percentage        : ");
  scanf("%f", &discount);

  printf ("\n\t\t\t\t\t\t\tEnter the tax  percentage            : ") ;
  scanf ("%f", &tax) ;

  discount_amount = (Total* discount)/100.0;
  Sub_Total =Total-discount_amount;
  tax_amount= (Sub_Total*tax) /100.0;
  Total_Amount =Sub_Total+tax_amount;

   printf ("\n\n\t\t\t\t\t\t\t\t\tBILL");
   printf("\n\t\t\t\t\t\t\t\t Buyer Name       :%s",  Buyer_Name);
   printf("\n\t\t\t\t\t\t\t\t Total Amount     :%d",  Total);
   printf("\n\t\t\t\t\t\t\t\t Discount Amount  :%f",  discount_amount);
   printf("\n\t\t\t\t\t\t\t\t Sub Total        :%d",  Sub_Total);
   printf("\n\t\t\t\t\t\t\t\t Tax Amount       :%f",  tax_amount);
   printf("\n\t\t\t\t\t\t\t\t Total Amount     :%f",  Total_Amount);

   printf("\n\n\t\t\t\t\t\t\t\tPress a key for return the menu\n\n");
   getch();
   menu();
   return;
}



void ViewDeleteProducts()
{
    char target[40];
	int found=0;
	FILE *sfile, *tfile;
	sfile=fopen("BATA.txt","r");
	tfile=fopen("TempFile.dat","w+");
	printf("\n\t\t\t\t\t\t\t\t Enter name to Delete: ");
	fflush(stdin);
	scanf("%s",target);
	target[0]=toupper(target[0]);
	while (fscanf(sfile,"%s %s %i %i %i\n",st.productname,st.productcomp, &st.price,&st.productid,&st.Qnt)!=EOF)
	{
		if(strcmp(target,st.productname)==0)
		{
			found=1;
		}
		else
		{
			fprintf(tfile,"%s %s %i %i %i\n", st.productname,st.productcomp, st.price,st.productid,st.Qnt);
		}
	}
			if(!found)
			{
				printf("\n\t\t\t\t\t\t\t\t Record not Found");
				getch();
				menu();
			}
			else
			{
				printf("\n\t\t\t\t\t\t\t\t Record deleted");
			}
			fclose(sfile);
			fclose(tfile);
			remove("BATA.txt");
			rename("TempFile.dat","BATA.txt");

			printf("\n\t\t\t\t\t\t\t\tPress any key to go to Main Menu!");
		while((st.c = getch()) =='\r');
		menu();

}

void EditEmployees()
{
    int index, valid;
	char target[40];
	FILE *fp, *rp;
	int a=0;
	int id;
	char edit;
	long int size=sizeof(st);
	if((fp=fopen("employee.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		menu();
	}
	else
	{
		rp = fopen("TempFile.dat","a");
		system("cls");
		printf("\t\t\t\t\t\t\t\tEnter Employee's' ID for edit:");
		scanf("%i",&id);
		fflush(stdin);
		while(fscanf(fp,"%s %s %i %i %i\n", st.employeename,st.position, &st.age, &st.idno,&st.salary)!=EOF)
		{
			if(id==st.idno)
			{

				a=1;
				printf("\n\t\t\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb Record Found \xdb\xdb\xdb\xdb\xdb");
				printf("\n\t\t\t\t\t\t\t\tEmployee's Name\t\t: %s",st.employeename);
				printf("\n\t\t\t\t\t\t\t\tItems's Position\t: %s",st.position);
				printf("\n\t\t\t\t\t\t\t\tAge\t\t\t: %i",st.age);
				printf("\n\t\t\t\t\t\t\t\tItem's ID\t\t: %i",st.idno);
				printf("\n\t\t\t\t\t\t\t\tItem's Salary\t\t:%i",st.salary);

				printf("\n\n\t\t\t\t\t\t\t\t\t*** New Record ***");
			do
				{

					fflush(stdin);
					printf("\n\t\t\t\t\t\t\t\tNew Employees's Name\t\t: ");
					gets(st.employeename); // get input string
					st.employeename[0]=toupper(st.employeename[0]);
					//iterate for every character in string
					for (index=0; index<strlen(st.employeename); ++index)
					{	//check if character is valid or not
						if(isalpha(st.employeename[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("\n Name contain invalid character. Please 'Enter' again");
						getch();


					}
				}while(!valid);	//while end here


				//Product Company
				do
				{
					char position[40];
					fflush(stdin);
					printf("\n\t\t\t\t\t\t\t\tNew Position\t\t\t:");
					gets(st.position); // get input string
					st.position[0]=toupper(st.position[0]);
					//iterate for every character in string
					for (index=0; index<strlen(st.position); ++index)
					{	//check if character is valid or not
						if(isalpha(st.position[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("\n Name contain invalid character. Please 'Enter' again");
						getch();


					}
				}while(!valid);

					do
			{
				printf("\n\t\t\t\t\t\t\t\tNew Age [25-45]\t\t\t:");
				scanf("%i",&st.age);
				if(st.age<25 || st.age>45)
				{
					printf("\n\tYou Cannot Enter the Age limit [25-45].Re-Enter.");
				}
			}while(st.age<25 || st.age>45);

				printf("\n\t\t\t\t\t\t\t\tEnter New Employee's Code\t:");
				scanf("%i",&st.idno);

				do
			{
				printf("\n\t\t\t\t\t\t\t\tNew Salary [10000-50000]\t:");
				scanf("%i",&st.salary);
				if(st.salary<10000 || st.salary>50000)
				{
					printf("\n\t\t\t\t\t\t\t\t\tEnter New Quantity[10000-50000] only.Re-Enter.");
				}
			}while(st.salary<10000 || st.salary>50000);


				printf("\t\t\t\t\t\t\tPress 'y' to edit the existing record or any key to cancel...");
				edit=getche();
				if(edit=='y' || edit=='Y')
				{
					fprintf(rp,"%s %s %i %i %i\n", st.employeename, st.position, st.age, st.idno,st.salary);
					fflush(stdin);
					printf("\n\n\t\t\t\t\t\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
				}
			}
			else
			{
				fprintf(rp,"%s %s %i %i %i\n", st.employeename, st.position, st.age, st.idno,st.salary);
				fflush(stdin);
			}

		}
		if(!a)
		{
			printf("\n\nTHIS ITEM DOESN'T EXIST!!!!");
		}
		fclose(rp);
		fclose(fp);
		remove("employee.txt");
		rename("TempFile.dat","employee.txt");
		getch();
	}
	menu();

}

void DeleteEmployees()
{
    char target[40];
	int found=0;
	FILE *sfile, *tfile;
	sfile=fopen("employee.txt","r");
	tfile=fopen("TempFile.dat","w+");
	printf("\n\t\t\t\t\t\t\t\t Enter name to Delete: ");
	fflush(stdin);
	scanf("%s",target);
	target[0]=toupper(target[0]);
	while (fscanf(sfile,"%s %s %i %i %i\n",st.employeename,st.position, &st.age,&st.idno,&st.salary)!=EOF)
	{
		if(strcmp(target,st.employeename)==0)
		{
			found=1;
		}
		else
		{
			fprintf(tfile,"%s %s %i %i %i\n", st.employeename,st.position, st.age,st.idno,st.salary);
		}
	}
			if(!found)
			{
				printf("\n\t\t\t\t\t\t\t\t Record not Found");
				getch();
				menu();
			}
			else
			{
				printf("\n\t\t\t\t\t\t\t\t Record deleted");
			}
			fclose(sfile);
			fclose(tfile);
			remove("employee.txt");
			rename("TempFile.dat","employee.txt");

			printf("\n\t\t\t\t\t\t\t\tPress any key to go to Main Menu!");
		while((st.c = getch()) =='\r');
		menu();

}
void Exit()
{
    return ;
}

