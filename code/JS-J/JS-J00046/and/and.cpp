#include <bits/stdc++.h>

using namespace std;
int a[200005];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long ans=1;
    int n,m;
    cin>>n>>m;
    int t=m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=a[i]&ans;
        }
    }
    else
    {
        sort(a+1,a+n+1,cmp);
        ans=a[1];
        for(int i=2;i<=m;i++)
        {
            ans=a[i]&ans;
        }
    }
    cout<<ans;
    return 0;
}
