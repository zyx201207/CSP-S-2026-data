#include <bits/stdc++.h>
#define int long long 
const int N=5e5+10;
using namespace std;
int n,m,ans1,sum,sum1,ans;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int zhi=1;
	for(int i=1;i<=n;++i)
	{
		sum1=a[i]*(i-zhi+1);
		sum+=a[i];
		while(m<sum1-sum)
		{
			sum1-=a[i];
			sum-=a[zhi];
			zhi++;
		} 
		//cout<<"i "<<zhi<<"\n";
		ans=max(ans,i-zhi+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/

