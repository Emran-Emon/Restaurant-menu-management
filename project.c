#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Restaurant
{
    char name[100];
    int id;
    int quantity;
    int price;

};

void display()
{
    struct Restaurant r[100];
    FILE *file;
    file = fopen("project.txt","r");
    if(file==NULL)
    {
        printf("File did not open successfully!");
    }
    else
    {
        for(int i=0; ; i++)
        {
            if(feof(file))
            {
                break;
            }
            fscanf(file,"%s",&r[i].name);
            fscanf(file,"%d",&r[i].id);
            fscanf(file,"%d",&r[i].quantity);
            fscanf(file,"%d\n",&r[i].price);
            printf("\nName is: %s\nId is: %d\nQuantity: %d\nUnit price: %d\n",r[i].name, r[i].id, r[i].quantity, r[i].price);

        }
    }
    fclose(file);
}

void searchFood()
{
    struct Restaurant r[100];
    int a=0;
    FILE *file;
    file = fopen("project.txt","r");
    if(file==NULL)
    {
        printf("File did not open successfully!");
    }
    for(int i=0; ; i++)
    {
        if(feof(file))
        {
            break;
        }
        fscanf(file,"%s",r[i].name);
        fscanf(file,"%d",&r[i].id);
        fscanf(file,"%d",&r[i].quantity);
        fscanf(file,"%d",&r[i].price);
        a++;
    }
    fclose(file);
    int flag=0;
    char n[100];
    printf("Enter the name you want to search: ");
    scanf("%s", n);
    for(int i=0; i<a; i++)
    {
        if(strcmp(r[i].name,n)==0)
        {
            flag=1;
            printf("\nName is: %s\nId is: %d\nQuantity: %d\nUnit price: %d\n",r[i].name, r[i].id, r[i].quantity, r[i].price);
        }
    }
    if(flag==0)
        printf("Information not found.\n");
}

void addFood()
{
    int n;
    printf("How many food item do you want to add: ");
    scanf("%d",&n);

    FILE *fp;

    fp=fopen("project.txt","a");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        struct Restaurant r[n];
        for(int i=0; i<n; i++)
        {
            printf("Enter food info:\n");

            fflush(stdin);
            printf("\tName: ");
            gets(r[i].name);
            fprintf(fp,"%s\t",r[i].name);

            printf("\tID: ");
            scanf("%d",&r[i].id);
            fprintf(fp,"%d\t",r[i].id);


            printf("\tQuatity: ");
            scanf("%d",&r[i].quantity);
            fprintf(fp,"%d\t",r[i].quantity);

            printf("\tPrice per unit: ");
            scanf("%d",&r[i].price);
            fprintf(fp,"%d\n",r[i].price);

            printf("\n");

        }
    }
    fclose(fp);
}

void deleteFood()
{
    int num;
    fflush(stdin);
    printf("Enter the food ID to remove: ");
    scanf("%d",&num);

    struct Restaurant r[1000];
    FILE *fp;
    int count;

    fp=fopen("project.txt","r");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        count=0;
        for(int i=0; ; i++)
        {
            if(feof(fp))
            {
                break;
            }
            else
            {
                fscanf(fp,"%s %d %d %d\n",&r[i].name,&r[i].id,&r[i].quantity,&r[i].price);
                count++;
            }
        }
    }
    fclose(fp);

    fp=fopen("project.txt","w");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        int flag=0;
        for(int i=0; i<count; i++)
        {
            if(r[i].id==num)
            {
                flag++;
                continue;
            }

            fprintf(fp,"%s\n",r[i].name);
            fprintf(fp,"%d\n",r[i].id);
            fprintf(fp,"%d\n",r[i].quantity);
            fprintf(fp,"%d\n",r[i].price);

        }
        if(flag==0)
        {
            Beep(610,500);
            printf("\nInvalid ID!!\n");
        }

        else
        {
            printf("\nFood Item Removed Successfully\n");
        }
    }
    fclose(fp);
}
void editFood()
{
    int num;
    fflush(stdin);
    printf("Enter food ID to edit: ");
    scanf("%d",&num);

    struct Restaurant r[1000];
    FILE *fp;
    int count;

    fp=fopen("project.txt","r");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        count=0;
        for(int i=0;  ; i++)
        {
            if(feof(fp))
            {
                break;
            }
            else
            {
                fscanf(fp,"%s %d %d\n",&r[i].name,&r[i].id,&r[i].quantity,&r[i].price);
                count++;
            }
        }
    }
    fclose(fp);

    fp=fopen("project.txt","w");
    if(fp==NULL)
    {
        printf("File Error!!");
    }
    else
    {
        int flag=0;
        for(int i=0; i<count; i++)
        {
            if(r[i].id==num)
            {
                flag++;
                printf("Enter new info of food id- %d:\n",r[i].id);
                fflush(stdin);
                printf("\tName: ");
                gets(r[i].name);
                fprintf(fp,"%s\n",r[i].name);

                printf("\tID: ");
                scanf("%d",&r[i].id);
                fprintf(fp,"%d\n",r[i].id);

                printf("\tQuantity: ");
                scanf("%d",&r[i].quantity);
                fprintf(fp,"%d\n",r[i].quantity);

                printf("\tPrice per unit: ");
                scanf("%d",&r[i].price);
                fprintf(fp,"%d\n",r[i].price);

                continue;
            }

            fprintf(fp,"%s\n",r[i].name);
            fprintf(fp,"%d\n",r[i].id);
            fprintf(fp,"%d\n",r[i].quantity);
            fprintf(fp,"%d\n",r[i].price);


        }
        if(flag==0)
        {
            Beep(610,500);
            printf("\nInvalid ID!!\n");
        }

        else
        {
            printf("\nFood Item Edited Successfully\n");
        }
    }
    fclose(fp);
}


int main()
{
    int a,b;
    while(1)
    {
        printf("                                   *************************************************\n");
        printf("                                   WELCOME TO OUR KITCHEN\n");
        printf("                                                     -WE CARE ABOUT YOUR GOOD HEALTH\n");
        printf("                                   *************************************************\n\n");
        printf("1.Admin\n2.Customer\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&a);

        switch(a)
        {
        case 1:
        {
            int x;
            printf("                                   ************************\n");
            printf("                                   WELCOME TO ADMIN WINDOW\n");
            printf("                                   ************************\n\n");
            printf("1. Add food item.\n2. Display info of all food.\n3. Delete food item.\n4. Edit food info.\n");
            printf("5. Exit\n");
            printf("Enter your choice: ");
            scanf("%d",&x);

            switch(x)
            {
            case 1:
            {
                addFood();
                break;
            }
            case 2:
            {
                display();
                break;

            }

            case 3:
            {
                deleteFood();
                break;

            }
            case 4:
            {
                editFood();
                break;

            }
            case 5:
            {
                printf("Thank you\n");
                return 0;
                break;
            }

            default:
                printf("Wrong input\n");
            }
            break;
        }
        case 2:
        {
            printf("                                   *************************\n");
            printf("                                   WELCOME TO CUSTOMER WINDOW\n");
            printf("                                   *************************\n\n");
            printf("1. Display all food item.\n2. Search food.\n3. Exit");
            int flag;
            printf("\n\nEnter your choice: ");
            scanf("%d",&flag);

            switch(flag)
            {
            case 1:
            {
                display();
                break;
            }
            case 2:
            {
                searchFood();
                break;
            }
            case 3:
            {
                return 0;
            }
            default:
                printf("Wrong input\n");
            }
            break;
        }
        case 3:
        {
            printf("Thank you for staying in touch!");
            return 0;
        }
        default:
            printf("Wrong input");
        }

    }
    return 0;
}
