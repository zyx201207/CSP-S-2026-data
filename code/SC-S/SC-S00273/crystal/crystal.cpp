/*
	因为我们只能单点+1。
	
	所以我们确定了要变的数后只有比他小的数会产生贡献。
	
	而我们又尽量选择较近的数，所以较远的数会被抛弃掉，且永远不会产生贡献。
	
	那我们维护一个双指针就行了。 
	
	OKT1大样例全过。
	
	差个眼，尽量后面来对拍。 
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int n,m;
ll a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll sum=0;
	int ans=0;
	for(int i=1,j=1;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-j);
		while(sum>m&&j<i)
		{
			sum-=(a[i]-a[j]);
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}