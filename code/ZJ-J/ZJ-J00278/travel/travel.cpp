#include<bits/stdc++.h>

using namespace std;

#define int long long
#define uint unsigned long long
#define inf (LLONG_MAX>>1)

char c1[10],c2[10],s1[10],s2[10];

signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    scanf("%s%s%s%s",c1,s1,c2,s2);
    if(c1[0]!=c2[0]||c1[1]!=c2[1])
    {
        printf("0000\n");
        return 0;
    }
    printf("1");
    int num1=(s1[0]-'0')*10+(s1[1]-'0'),num2=(s2[0]-'0')*10+(s2[1]-'0');
    if(num1!=num2)
    {
        printf("000\n");
        return 0;
    }
    printf("1");
    if(s1[2]>='D'&&s2[2]>='D')
    {
        printf("11\n");
        return 0;
    }
    else if(s1[2]<='C'&&s2[2]<='C')
    {
        printf("1");
        if((s1[2]=='C'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C'))
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }
    }
    else
    {
        printf("00\n");
    }
    return 0;
}