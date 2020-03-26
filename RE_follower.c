#include<stdio.h>
#include<stdlib.h>

int check_str(char arr[])         //This function is to check if the string contains only a , b , c  
{
    int i=0,flag=0;
    while(arr[i]!='\0')
    {
        if(arr[i]=='a'|| arr[i]=='b' || arr[i]=='c')
        {
            i++;
        }
        else
        {
            flag=1;
            break;
        }
    }
    return flag;
}

int check_R(char a[])          //This function is the real string check that checks the string follows the regular expression or not 
                              //(cont.)i.e (a+b)*cc(a+b)*.....This function is only executed if the check_str function directs it to do so. 
{
    
    int i=1,l,f=1,k=0,flag=0;

    for(l=0;a[l]!='\0';l++);

    if(a[0]=='a'|| a[0]=='b')
    {
    while(a[i]!='\0')
    {
        if(a[i]=='a'||a[i]=='b')
        {
            i++;
        }
        else if (a[i]=='c')
        {
            if(a[i+1]=='c')
            {
                i=i+2;
                break;
            }
            else
            {
                flag=1;
                f=0;
                break;
            }
            
        }
        
    }
    if(i<l && f==1)
    {
        while(i<l)
        {
            if(a[i]=='a'||a[i]=='b')
            {
                i++;
            }
            else
            {
                flag=1;
                k=1;
                break;
            }
        }
        if(k==0){
            flag=0;
        }
        
    }
    }
    else
    {
         flag=1;
    }

    return flag;
    
}



int main()   // MAIN FILE 
{
    char fname[100];
    FILE *f;
    printf("Enter the file name ....PLEASE ADD A .txt extension to your file name\n"); // ACCEPTING FILE NAME
    scanf("%s",fname);
    f=fopen(fname,"r");

    if (f == NULL)
    {
        printf("FILE NOT FOUND!");
        exit(0);
    }
    else
    {
        char c;
        char str[100],arr[100];
        

        int i=0,j;
        for(j=0;j<100;j++)
               {
                   str[j]='\0';
               }
        printf("The strings from the text file that belongs to the Language L following regular expression R are:\n");
        while((c=fgetc(f))!=EOF)
        {
            if (c==' '|| c=='\n')
            {
                 
                int k = check_str(str);
                int r;
                if(k==0)
                {
                    r=check_R(str);
                    if(r==0)
                    {
                        printf("%s",str);
                    }
                      
                }                
               i=0;
               printf(" ");

               for(j=0;j<100;j++)
               {
                   str[j]='\0';
               }
            }
            else
            {
                str[i]=c;
                i++;
            }
            
        }
        if(feof)    // FOR THE LAST WORD OF THE FILE
        {
            int k,r;
            if(k=check_str(str)==0)
            {
                 r=check_R(str);
                    if(r==0)
                    {
                        printf("%s",str);
                    }         
            }
        }
        
    }
    fclose(f);  
}
