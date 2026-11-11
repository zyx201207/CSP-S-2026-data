#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int s[200005];
int maxn;
void dfs(int step,int st)
{
    if(step>m)
    {
        int sum=s[1];
        for(int i=2;i<=m;i++)
        {
            sum&=s[i];
        }
        if(sum>=maxn)
        {

            maxn=sum;
        }
        return;
    }
    for(int i=st+1;i<=n;i++)
    {
        dfs(step,i);
        s[step]=a[i];
        dfs(step+1,i);
    }

    return;
}
bool check(int n,int m)
{
    bool flag=true;
    for(int i=n;i>=n-m+2;i--)
    {
        if(a[i-1]*2+1!=a[i])
        {
            flag=false;
            break;

        }
    }
    return flag;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxnn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxnn=max(maxnn,a[i]);
    }
    if(m==1)
    {

        cout<<maxnn;
        return 0;
    }
    if(m==n)
    {
        int num=a[1];
        for(int i=2;i<=n;i++)
        {
            num&=a[i];
        }
        cout<<num;
        return 0;
    }
    if(check(n,m))
    {

        cout<<a[n-m+1];
        return 0;
    }
    dfs(1,0);
    cout<<maxn;
    return 0;
}
