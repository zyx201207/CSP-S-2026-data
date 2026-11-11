#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],maxx=-1;
bool dp[200001];
bool mj(int y)
{
    for(int i=1;i<=20;i++)
    {
        if(y+1==pow(2,i)) return 1;
    }
    return 0;
}
bool niu()
{
    for(int i=1;i<=n;i++) if(mj(a[i])==0) return 0;
    return 1;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1)
    {
        for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
    }
    else if(m==2)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxx=max((a[i]&a[j]),maxx);
            }
        }
    }
    else if(niu()==1)
    {
        sort(a+1,a+n+1);
        cout<<a[m];
        return 0;
    }
    else if(m==n)
    {
        maxx=a[1];
        for(int i=2;i<=n;i++) maxx=maxx&a[i];
    }
    cout<<maxx;
    return 0;
}
