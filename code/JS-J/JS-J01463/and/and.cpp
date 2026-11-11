#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')x=10*x+(ch-'0'),ch=getchar();
    return x*f;
}
int n,m;
long long a[200001],ans=-9999999;
void dfs(int p,int cnt,long long x)
{
    if(cnt==m)
    {
        ans=max(ans,x);
        return;
    }
    if(p==n+1)return;
    dfs(p+1,cnt,x);
    dfs(p+1,cnt+1,x&a[p]);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)a[i]=read();
    if(m==2)
    {
        for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
        cout<<ans;
    }
    else if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    else if(m==n)
    {
        long long s=2147483647;
        for(int i=1;i<=n;i++)s&=a[i];
        cout<<s;
    }
    else
    {
        if(n<=25)
        {
            dfs(0,0,2147483647);
            cout<<ans;
        }
        else
        {
            sort(a+1,a+n+1);
            long long s=a[n];
            for(int i=n;i>=n-m+1;i--)s&=a[i];
            cout<<s;
        }
    }
    return 0;
}
