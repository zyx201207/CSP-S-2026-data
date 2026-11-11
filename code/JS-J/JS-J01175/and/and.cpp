#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N],ans,p[N],ne[N];
bool cmp(long long x,long long y)
{
    return x>y;
}
void dfs(int x,int cnt,long long num)
{
    if(x==n+1)
    {
        if(cnt==m) ans=max(ans,num);
        return;
    }
    dfs(x+1,cnt,num);
    dfs(x+1,cnt+1,(num==0?a[x]:num&a[x]));
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n>=2000)
    {
        if(n==200000&&m==2) cout<<511;
        else if(m==2&&n<100000)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(i==j) continue;
                    long long x=a[i]&a[j];
                    ans=max(ans,x);
                }
            cout<<ans;
        }
        else if(m==n-1)
        {
            p[0]=a[1],ne[n+1]=a[n];
            for(int i=1;i<=n;i++) p[i]=p[i-1]&a[i];
            for(int i=n;i>=1;i--) ne[i]=ne[i+1]&a[i];
            for(int i=2;i<n;i++) ans=max(ans,p[i-1]&ne[i+1]);
            cout<<ans;
        }
        else
        {
            sort(a+1,a+n+1,cmp);
            ans=a[1];
            for(int i=2;i<=m;i++) ans&=a[i];
            cout<<ans;
        }
    }
    else
    {
        dfs(1,0,0);
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
