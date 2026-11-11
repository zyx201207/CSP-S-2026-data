#include<bits/stdc++.h>
using namespace std;
int n,d,c,t,a[100001];
pair<int,int>s[100001];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
    return x*f;
}
void dfs(int p,int m,int cnt)
{
    if(cnt==m)
    {
        if(s[p].first==0)s[p].first=m,s[p].second++;
        else
        {
            if(s[p].first>m)s[p].first=m,s[p].second=1;
            else if(s[p].first==m)s[p].second++;
        }
        return;
    }
    for(int i=p+1;i<=n;i++)
    {
        if(a[i]-a[p]<=d)dfs(i,m,cnt+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();
    t=read();
    while(t--)
    {
        int ans=0;
        n=read();
        d=read();
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<=n-3;i++)
        {
            for(int j=3;j<=n-i+1;j++)
            {
                dfs(i,j,1);
                for(int k=1;k<=n;k++)if(s[k].second==2)ans++;
                memset(s,0,sizeof s);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

