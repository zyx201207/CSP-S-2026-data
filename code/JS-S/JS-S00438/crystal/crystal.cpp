#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //freopen("crystal4.in","w",stdin);       诈骗
    //freopen("cyrstal.out","r",stdout);      诈骗
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0,i=1,j=1,tmp=0;
    while(i<n||j<n)
    {
        if(i>j)
        {
            j=i;
        }
        ans=max(ans,j-i+1);
        if(j<n&&tmp+(a[j+1]-a[j])*(j+1-i)<=m)
        {
            tmp+=(a[j+1]-a[j])*(j+1-i);
            j++;
        }
        else
        {
            tmp-=a[j]-a[i];
            i++;
        }
    }
    cout<<ans;
    return 0;
}
//≈100 pts
