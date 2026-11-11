#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        int ans=0;
        if((a[i]-a[i-1])+a[i]-a[i-2]>m)continue;
        for(int j=1;j<i;j++)
        {
            ans+=a[i]-a[j];
        }
        if(ans<=m)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}
