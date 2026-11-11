#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int dfs(int x,int b)
{
    long long sum1=0;
    for(int i=x-1;i>=1;i--)
    {
        if(b-(a[x]-a[i])>=0)
        {
            b-=(a[x]-a[i]);
            sum1++;
        }
        else break;
    }
    return sum1+1;
}
int main()
{
    freopen("crytal.in","r",stdin);
    freopen("crytal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n+1);
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        int stemp=dfs(i,m);
        if(stemp>sum) sum=stemp;
    }
    cout<<sum;
    return 0;
}
