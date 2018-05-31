//单词计数
void  Wordcount(FILE *fp)
{
    int sum=0;
    char str;
    char temp[20]={0};
    int flag = 0;
    int j = 0;
    while(fscanf(fp,"%c",&str)!=EOF)
    {
        if(!(str >= 'a' && str <= 'z') && !(str >= 'A' && str <= 'Z')){
            for (int i = 0; i < strlen(temp); i ++) {
                if((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= 'A' && temp[i] <= 'Z')){
                    flag = 1;
                    break;
                }
            }
        }
        else{
            temp[j] = str;
            j ++;
        }
        if(flag == 1){
            sum ++;
            flag = 0;
            j = 0;
            memset(temp, 0, sizeof(temp));
        }
    }//这是注释
    
    cout<<"the num of word is:"<<sum<<endl;
    
    fclose(fp);
}