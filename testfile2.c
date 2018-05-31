//这是注释
int main(int argc, char *argv[])
{
    FILE *fp;
    if(strcmp("-c",argv[1])==0)
    {
        fp=fopen(argv[2],"r");
        Charcount(fp);
    }
    if(strcmp("-w",argv[1])==0)
    {
        fp=fopen(argv[2],"r");
        Wordcount(fp);
    }
    if(strcmp("-l",argv[1])==0)
    {
        fp=fopen(argv[2],"r");
        Linecount(fp);
    }
    if(strcmp("-s",argv[1])==0)
    {
        char str[30][100];
        int i=0;
        system("dir /B > log.txt");
        fp=fopen("log.txt","r");
        while(!feof(fp))
        {
            char ch2[100];
            fgets(ch2,100,fp);
            int len=strlen(ch2);
            if(ch2[len-2]=='c'&&ch2[len-3]=='.'&&len>3)
            {
                strcpy(str[i],ch2);
                str[i][len-1]='\0';
                i++;
            }
        }//注释
        int n=i;
        for(i=0;i<n;i++)
        {
            FILE *f1=fopen(str[i],"r");
            printf("%s:\n",str[i]);
            Charcount(f1);
            f1=fopen(str[i],"r");
            Linecount(f1);
            f1=fopen(str[i],"r");
            Wordcount(f1);
            f1=fopen(str[i],"r");
            Count(f1);
            
        }
    } 
    if(strcmp("-a",argv[1])==0)
    {
        fp=fopen(argv[2],"r");
        Count(fp);
        fclose(fp);
    }
}