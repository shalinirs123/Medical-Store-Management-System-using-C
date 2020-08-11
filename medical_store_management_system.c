#include<stdio.h>
 #include<conio.h>
 #include<string.h>
 #include<ctype.h>
 struct Medicine{
   int id,price,quantity;
   char medicneName[100],Company[100],Mfg_Date[11],Exp_Date[11],info[5000];
  }m[100];
 void buy_Med(int number);
  void view_Med(int number);
 void search_Med(int number);
 void Add_Med(int number,struct Medicine m[]);
 void Delete_Med(int number);
 void edit_Med(int number);
 main()
 {
   int i,j,choice,number=0,c;
   for(i=0;i<100;i++)
   {
    m[i].id=0;
   m[i].price=0;
   m[i].quantity=0;
   strcpy(m[i].Mfg_Date,"");
  strcpy(m[i].Exp_Date,"");
   strcpy(m[i].medicneName,"");
   strcpy(m[i].Company,"");
   strcpy(m[i].info,"");
   }
   m[0].id=1;
   m[0].price=120;
   m[0].quantity=30;
   strcpy(m[0].Mfg_Date,"23-04-2016");
  strcpy(m[0].Exp_Date,"24-04-2020");
   strcpy(m[0].medicneName,"Paracetmol");
   strcpy(m[0].Company,"ABCD");
   strcpy(m[0].info,"Good Medicine for Fever");
   do{
   printf("Enter\n1 - Add Medicine\n2 - Delete a Medicine\n3 - Search Medicine Information\n4 - Stock of Medicine in Store\n5 - Purchase Medicine\n6 - Change Quantity of Medicine\n");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:
    {
     buy_Med(number+1);
     break;
    }
     case 2:
    {
        view_Med(number+1);
       break;
      }
      case 3:
      {
       search_Med(number+1);
       break;
      }
      case 4:
      {
       ++number;
       Add_Med(number,m);
       break;
      }
      case 5:
      {
       Delete_Med(number+1);
       break;
      }
      case 6:
      {
       edit_Med(number+1);
       break;
      }
   }
     printf("To Continue with other Options Enter 1 Else any other number\n");
     scanf("%d",&c);
   }while(c==1);

 }
 void buy_Med(int number)
 {
  int id,check,j,quantity,flag=0;
  char name[1000];
  printf("Enter 1 if you know ID\nelse any other number to enter Name of Medicine\n");
  scanf("%d",&check);
  if(check==1)
  {
   printf("Enter Id of Medicine to be purchased\n");
   scanf("%d",&id);
   for(j=0;j<number;j++)
   {
    if(m[j].id==id)
    {
     flag=1;
     int c;
     printf("Details of Medicine are\n");
     printf("Name%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n",m[j].medicneName,m[j].price,m[j].quantity,m[j].Company,m[j].Mfg_Date,m[j].Exp_Date);
      if(strcmp(m[j].info,"")==0)
      {
       printf("Medicine Not Available\n");
      }
      else
      {
       printf("Medicine Info=%s\n",m[j].info);
      }
     printf("Do you want to purchase %s \nEnter 1 if yes else any other number\n",m[j].medicneName);
     scanf("%d",&c);
     if(c==1)
     {
      printf("Enter Quantity\n");
      scanf("%d",&quantity);
      if(m[j].quantity>quantity)
      {
       printf("Total Price=%d\n",quantity*m[j].price);
      }
      else{
       printf("Please Enter quantity below Available Quantity\n");
      }
     }
     break;
    }
   }
   if(flag==0)
   {
    printf("Entered medicine Id Not Found\n");
   }
  }
  else
  {
   printf("Enter the Name to be searched and Purchased\n");
   gets(name);
   for(j=0;j<number;j++)
   {
    if(strcmp(m[j].medicneName,name)==0)
    {
     flag=1;
     int c;
     printf("the details of Medicine are\n");
     printf("Name=%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n",m[j].medicneName,m[j].price,m[j].quantity,m[j].Company,m[j].Mfg_Date,m[j].Exp_Date);
      if(strcmp(m[j].info,"")==0)
      {
       printf("Medicine Info Not Available\n");
      }
      else
      {
       printf("Medicine Info=%s\n",m[j].info);
      }
     printf("Do you want to purchase %s \nEnter 1 if yes else any other number\n",m[j].medicneName);
     scanf("%d",&c);
     if(c==1)
     {
      printf("Enter Quantity\n");
      scanf("%d",&quantity);
      if(m[j].quantity>quantity)
      {
       printf("Total Price=%d\n",quantity*m[j].price);
      }
      else{
       printf("Please Enter quantity below Available Quantity\n");
      }
     }
     break;
    }
   }
   if(flag==0)
   {
    printf("Entered medicine Name Not Found\n");
   }
  }
 }
 void search_Med(int number){
   int j,flag=0;
  char name[100];
  printf("Enter Name of the medicine you want to search\n");
  scanf("%s",name);
  for(j=0;j<number;j++)
  {
   if(strcmp(m[j].medicneName,name)==0)
   {
    flag=1;
    printf("the details of Medicine are\n");
    printf("Name=%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n",m[j].medicneName,m[j].price,m[j].quantity,m[j].Company,m[j].Mfg_Date,m[j].Exp_Date);
    if(strcmp(m[j].info,"")!=0)
    {
     printf("Review=%s\n",m[j].info);
    }
    else
    {
     printf("Info Not Available\n");
    }
   }
  }
  if(flag==0)
  {
   printf("Entered medicine Name Not Found\n");
  }
 }
 void view_Med(int number){
  int j;
  if(number!=0)
  {
      printf("All Available medicines are\n");
   for(j=0;j<number;j++)
   {
    if(m[j].id!=0){
    printf("Id=%d\nName=%s\t\tPrice=%d\tAvailable Quantity=%d\nCompany=%s\t\tMfg Date=%s\tExp Date=%s\n",m[j].id,m[j].medicneName,m[j].price,m[j].quantity,m[j].Company,m[j].Mfg_Date,m[j].Exp_Date);
    if(strcmp(m[j].info,"")!=0)
    {
     printf("Review=%s\n",m[j].info);
    }
    else
    {
     printf("Review Not Available\n");
    }
      }
   }
  }
  else{
   printf("No Medicines Available\n");
  }
 }
 void Add_Med(int number,struct Medicine m[])
 {
  char name[100];
  printf("Enter Medicine Id\n");
  scanf("%d",&(m[number].id));
  printf("Enter Medicine name\n");
  scanf("%s",name);
  strcpy(m[number].medicneName,name);
  printf("Enter the Company Name\n");
  scanf("%s",(m[number].Company));
  printf("Enter Manufactured Date\n");
  scanf("%s",(m[number].Mfg_Date));
  printf("Enter Expiry Date\n");
  scanf("%s",(m[number].Exp_Date));
  printf("Enter Quantity\n");
  scanf("%d",&(m[number].quantity));
  printf("Enter Price\n");
  scanf("%d",&(m[number].price));
  strcpy(m[number].info,"");
  printf("Medicine with id %d Added Successfully\n",m[number].id);
 }

 void Delete_Med(int number)
 {
  int id,j,flag=0,num;
  printf("Enter Id to be deleted\n");
  scanf("%d",&id);
  for(j=0;j<number;j++)
  {
   if(m[j].id==id)
   {
    flag=1;
    m[j].id=0;
    m[j].price=0;
    m[j].quantity=0;
    strcpy(m[j].medicneName,"");
    strcpy(m[j].Company,"");
    strcpy(m[j].Mfg_Date,"");
    strcpy(m[j].Exp_Date,"");
    strcpy(m[j].info,"");
    num=j;
    break;
   }
  }
  if(flag==1)
  {
   printf("Medicine with %d is Deleted Successfully\n",id);
  }
 }

 void edit_Med(int number)
 {
  int id,quantity,choice,c,j;
  printf("Enter id to edit\n");
  scanf("%d",&id);
  for(j=0;j<number;j++)
  {
   if(m[j].id==id && m[j].id!=0)
   {
    do
    {
        printf("Enter\n1 - Change Quantity\n2 - Change Price\n3 - Change Name\n4 - Change Company\n5 - Change Manufaturing Date\n6 - Change Expiry Date\n7 - Change Info\n");
        scanf("%d",&choice);
        if(choice==1)
        {
         int quantity;
         printf("Enter Quantity to edit\n");
         scanf("%d",&quantity);
         m[j].quantity=quantity;
         printf("Quantity changed Successfully\n");
        }
        if(choice==2)
        {
         int price;
         printf("Enter Price to be editted\n");
         scanf("%d",&price);
         m[j].price=price;
         printf("Price changed Successfully\n");
        }
        if(choice==3)
        {
         char name[100];
         printf("Enter Name to be edited\n");
         gets(name);
         strcpy(m[j].medicneName,name);
         printf("Medicine Name changed Successfully\n");
        }
        if(choice==4)
        {
         char company[100];
         printf("Enter company to be changed\n");
         gets(company);
         strcpy(m[j].Company,company);
         printf("Company changed Successfully\n");
        }
        if(choice==5)
        {
         char mfg[11];
         printf("Enter Manufacturing date to be editted\n");
         gets(mfg);
         strcpy(m[j].Mfg_Date,mfg);
         printf("Manufacturing Date changed Successfully\n");
        }
        if(choice==6)
        {
         char exp[11];
         printf("Enter Expiry date to be changed\n");
         gets(exp);
         strcpy(m[j].Exp_Date,exp);
         printf("Expiry Date changed Successfully\n");
        }
        if(choice==7)
        {
         char info[100];
         printf("Enter Info to be changed(Less than 100 Characters)\n");
         gets(info);
         strcpy(m[j].info,info);
         printf("Info changed Successfully\n");
        }
        if(choice<=0 && choice>7)
        {
         printf("Enter valid Choice\n");
        }
        printf("Enter 1 to Change other Details Else any other number\n");
        fflush(stdin);
        scanf("%d",&c);
    }while(c==1);

    break;
   }
  }
 }
