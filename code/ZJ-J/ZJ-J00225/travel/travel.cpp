#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e5+10;
char c1[maxn],s1[maxn],c2[maxn],s2[maxn];
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
    if(c1[1]!=c2[1]||c1[2]!=c2[2])
    {
        printf("0000");
    }
    else
    {
        printf("1");
        if(s1[1]==s2[1]&&s1[2]==s2[2])
        {
            printf("1");
            if(s1[3]>s2[3]) swap(s1[3],s2[3]);
            if(s1[3]=='D'&&s2[3]=='F')
            {
                printf("11");
            }
            else if(s1[3]=='D')
            {
                printf("00");
            }
            else if(s1[3]=='A'&&s2[3]!='B'&&s2[3]!='C')
            {
                printf("00");
            }
            else if(s1[3]=='A'&&s2[3]=='C')
            {
                printf("10");
            }
            else if(s1[3]=='A')
            {
                printf("11");
            }
            else if(s1[3]=='B'&&s2[3]=='C')
            {
                printf("11");
            }
            else if(s1[3]=='B')
            {
                printf("00");
            }
            else if(s1[3]=='C')
            {
                printf("00");
            }
        }
        else
        {
            printf("000");
        }
    }
    return 0;
}