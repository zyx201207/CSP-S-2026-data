#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int a[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<500005;i++)
    {
    	a[i]=0x7fffffffffffffff;
	}
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int i=0,j=0;
    int cost=0;
    int ans=1;
    for(;i<=j&&j<n;i++)
    {
    	while(cost<=m&&j<n)
    	{
    		j++;
    		cost+=(a[j]-a[j-1])*(j-i);
		}
		//刚刚爆了，退掉最后一次操作的花费 
		cost-=(a[j]-a[j-1])*(j-i);
		j--;
		ans=max(ans,j-i);
    	//i右移，退掉这一列的花费
    	cost-=a[j]-a[i]; 
	}
    cout<<ans+1;
    return 0;
}
