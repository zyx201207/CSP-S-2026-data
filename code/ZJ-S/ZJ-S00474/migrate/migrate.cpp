#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
    bool flag=false;
    char c=getchar();
    while (!isdigit(c))
    {
        if (c=='-')
            flag=true;
        c=getchar();
    }
    long long ans=0;
    while (isdigit(c))
    {
        ans=ans*10+c-48;
        c=getchar();
    }
    return flag?-ans:ans;
}
void write(const long long x)
{
    if (x>9)
        write(x/10);
    putchar(x%10+48);
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    const int c=read();
    int T=read();
    while (T--)
    {
        const int n=read();
        const long long d=read();
        vector<long long>x(n+2);
        x[0]=0xC000000000000000;
        x[n+1]=0x3fffffffffffffff;
        vector<bool>f(n+1,false);
        int len=0;
        for (int i=1;i<=n;++i)
            x[i]=read();
        for (int i=1;i<=n-3;++i)
            if (x[i+1]-x[i]<=d&&x[i+2]-x[i]<=d&&x[i+3]-x[i]>d&&x[i+3]-x[i+1]<=d&&x[i+3]-x[i+2]<=d)
                f[i]=true;
        vector<long long>sum(n+1);
        long long ans=0;
        /*for (int i=1;i<=n;++i)
        {
            int cnt=0;
            int j=i+1;
            while (j<=n)
            {
                if (f[i])
                    cnt++;
                if (cnt==1)
                {
                    j=i+3;
                    ans+=1;
                }
                else if (cnt>1)
                    break;
                if (a[j+1]-a[j]<=d)
                    j++;
            }
        }*/
        puts("0");
    }
    return 0;
}