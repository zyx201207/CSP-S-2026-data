#include <bits/stdc++.h>
using namespace std;
#define int long long
char c1[5],s1[5],c2[5],s2[5];
int R1,X1;
int R2,X2;
int ans[5];
int cvt(char c)
{
    if(c<='C')
        return 1;
    return 0;
}
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf(" %s",c1+1);
    scanf(" %s",s1+1);
    scanf(" %s",c2+1);
    scanf(" %s",s2+1);
    R1=(c1[1]-'0')*10+c1[2]-'0';
    X1=(c2[1]-'0')*10+c2[2]-'0';
    ans[1]=(R1==X1);
    if(ans[1])
    {
        R2=(s1[1]-'0')*10+s1[2]-'0';
        X2=(s2[1]-'0')*10+s2[2]-'0';
        ans[2]=(R2==X2);
        if(ans[2])
        {
            char R3=s1[3];
            char X3=s2[3];
            int k1=cvt(R3);
            int k2=cvt(X3);
            ans[3]=(k1==k2);
            if(ans[3])
            {
                if(k1==1)
                {
                    if(R3=='A')
                    {
                        if(X3=='B')
                        {
                            ans[4]=1;
                        }
                    }
                    else if(R3=='B')
                    {
                        ans[4]=1;
                    }
                    else
                    {
                        if(X3=='B')
                        {
                            ans[4]=1;
                        }
                    }
                }
                else
                {
                    ans[4]=1;
                }
            }
        }
    }
    for(int i=1;i<=4;++i)
        printf("%lld",ans[i]);
    return 0;
}
