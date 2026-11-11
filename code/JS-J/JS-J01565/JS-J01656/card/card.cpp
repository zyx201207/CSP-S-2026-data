#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],last[M],repeat;
bool vis[N],choose,change=1;
long long read()
{
    long long a=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
    return a;
}
void print(long long a)
{
    if(a<0){putchar('-');a=-a;}
    if(a>9)print(a/10);
    putchar(a%10+'0');
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        last[a[i]]=i;
        if(a[i]<a[i-1])
            choose=1;
    }
    if(n>5000&&!choose)
    {
        for(int i=1;i<=n;i++)
            ans[a[i]]=i;
    }
    else
    {
        for(int i=1;i<=n;i+=repeat)
        {
            repeat=1,change=!change;
            while(a[i]==a[i+repeat])
                repeat++;
            for(int j=i;j<=n;j++)
            {
                if(vis[j]==change)
                    continue;
                for(int k=j;k<=last[a[j]];k++)
                    vis[k]=change;
                ans[a[j]]+=repeat;
            }
        }
    }
    for(int i=1;i<=m;i++)
        print(ans[i]),putchar(' ');
    return 0;
}
