#include<bits/stdc++.h>
using namespace std;
int n,m;
char s1[5],s2[5];
bool IsNext(char c,char c2)
{
    if(c+1==c2||c-1==c2) return true;
    return false;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%s%d%s",&n,s1,&m,s2);
    if(n==m){
        printf("1");
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            printf("1");
            if((s1[2]>'C')==(s2[2]>'C'))
            {
                printf("1");
                if(IsNext(s1[2],s2[2])) printf("1");
                else printf("0");
            }
            else printf("00");
        }
        else printf("000");
    }
    else printf("0000");
    return 0;
}
