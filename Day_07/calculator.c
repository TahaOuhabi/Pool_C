#include <stdio.h>
#include <math.h>
#include <string.h>
char ops_hist[5][100];
int current=0;
void add_to_history(const char* entry){
    strcpy(ops_hist[current],entry);
    current=(current+1)%5;
}
long long factorial(int n){
    long long result=1;
    for(int i=1;i<=n;i++)
        result*=i;
    return result;
}
int main(void){
    char command[10];
    double num1,num2;
    char text[100];
    printf("CLI Calculator with history (last 5 operations)\n");
    printf("Commands:\na+b\na-b\na*b\na/b\nfact x\nsqrt x\npwr2 x\npwr3 x\n");
    printf("Type 'history' to show last 5 operations\nType 'exit' to quit\n");
    while(1){
        printf("-> ");
        scanf("%s",command);
        if(strcmp(command,"exit")==0) break;
        if(strcmp(command,"history")==0){
            printf("----- History -----\n");
            for(int i=0;i<5;i++){
                if(strlen(ops_hist[i])>0)
                    printf("%s\n",ops_hist[i]);
            }
            continue;
        }
        if(strcmp(command,"fact")==0){
            scanf("%lf",&num1);
            long long res=factorial((int)num1);
            sprintf(text,"fact(%d)=%lld",(int)num1,res);
            add_to_history(text);
            printf("%s\n",text);
            continue;
        }
        if(strcmp(command,"sqrt")==0){
            scanf("%lf",&num1);
            double res=sqrt(num1);
            sprintf(text,"sqrt(%.2f)=%.2f",num1,res);
            add_to_history(text);
            printf("%s\n",text);
            continue;
        }
        if(strcmp(command,"pwr2")==0){
            scanf("%lf",&num1);
            double res=num1*num1;
            sprintf(text,"%.2f^2=%.2f",num1,res);
            add_to_history(text);
            printf("%s\n",text);
            continue;
        }
        if(strcmp(command,"pwr3")==0){
            scanf("%lf",&num1);
            double res=num1*num1*num1;
            sprintf(text,"%.2f^3=%.2f",num1,res);
            add_to_history(text);
            printf("%s\n",text);
            continue;
        }
        scanf("%lf%lf",&num1,&num2);
        double res=0;
        if(strcmp(command,"+")==0) res=num1+num2;
        else if(strcmp(command,"-")==0) res=num1-num2;
        else if(strcmp(command,"*")==0) res=num1*num2;
        else if(strcmp(command,"/")==0) res=num1/num2;
        else {
            printf("Unknown operation\n");
            continue;
        }
        sprintf(text,"%.2f%s%.2f=%.2f",num1,command,num2,res);
        add_to_history(text);
        printf("%s\n",text);
    }
    return 0;
}
