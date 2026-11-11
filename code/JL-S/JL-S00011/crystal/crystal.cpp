#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[500005],m,p;
bool flag;
bool cmp(int a,int b)
{
    return a>b;
}
int fun()
{
    int b[500005],j=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]!=a[i])
            j++;
        else
            b[j]++;
    }
    sort(b,b+j,cmp);
    return b[0];
}
void dfs(int i,int maxx)
{
    if(i==m)
    {
        ans=max(ans,maxx);
        return;
    }
    for(int j=1;j<=n;j++)
    {
        a[j]++;
        int h=fun();
        dfs(i+1,h);
        a[j]--;
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    p=a[0];
    if(p<0)
    {
        flag=true;
        for(int i=0;i<n;i++)
            a[i]+=abs(p);
    }
    int q=fun();
    ans=q;
    dfs(0,q);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
