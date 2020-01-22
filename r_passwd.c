#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
int random_it(int check,int lower_bound,int upper_bound)
{
    int len,c=1;
    do
    {
        len=(char*)malloc(sizeof(char));
        len=len%(upper_bound+1);
        if(check==1)                                                    //check 1 for special character.
        {
            if((len>=33&&len<65)||(len>=91&&len<97)||(len>=123&&len<=126))
                return(len);
        }
        else
        if(len>=lower_bound&&len<=upper_bound)
        {
            c=0;
            break;
        }
    }while(c!=0);
    return(len);
}
int main()
{
    int ch,character,q,choice,i,length;
    char first,x[50];
    do
    {
        q=0;
        while(q!=1)
        {
            printf("\nPress 1 to generate password\nPress 2 to exit :");
            gets(x);
            if(x[1]=='\0')
            {
                ch=(int)x[0];
                ch=ch-48;
                if(ch>=1&&ch<=2)
                {
                    q=1;
                    break;
                }
            }
            if(q==0)
                printf("\nWrong choice,enter again");
        }
        switch(ch)
        {
        case 1:     system("cls");
                    printf("\nPassword :");
                    length=random_it(0,12,32);
                    character=random_it(0,97,122);
                    first=(char)character;
                    printf("%c",first);
                    for(i=1;i<length-1;i++)
                    {
                            choice=random_it(0,1,4);
                            if(choice==1)
                            {
                                character=random_it(0,97,122);
                                first=(char)character;
                                printf("%c",first);
                            }
                            if(choice==2)
                            {
                                character=random_it(0,65,90);
                                first=(char)character;
                                printf("%c",first);
                            }
                            if(choice==3)
                            {
                                character=random_it(0,0,9);
                                printf("%d",character);
                            }
                            if(choice==4)
                            {
                                character=random_it(1,33,126);
                                printf("%c",character);
                            }
                    }
                    character=random_it(0,65,90);
                    first=(char)character;
                    printf("%c\n",first);
        }
    }while(ch!=2);
    return(0);
}
