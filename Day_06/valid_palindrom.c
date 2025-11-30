#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool p(char*s,int l,int r){
    if(l>=r) return true;
    else if(s[l]!=s[r]) return false;
    else return p(s,l+1,r-1);
}
bool palindrome(char*s){return p(s,0,strlen(s)-1);}
int main(){
    char t[255];
    scanf("%254s",t);
    if(palindrome(t)) printf("Palindrome\n");
    else printf("pas palindrome\n");
    return 0;
}
