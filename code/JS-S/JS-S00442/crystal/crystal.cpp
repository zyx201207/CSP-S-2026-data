#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ma;
int ans=0;
int a[500010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        int sum=1;
        ma=m;
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]-a[j]<=ma)ma-=(a[i]-a[j]),sum+=1;
        }
        ans=max(sum,ans);
    }
    cout<<ans;
    return 0;
}

