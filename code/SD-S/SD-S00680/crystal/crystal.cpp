#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],cur,S[maxn],SS[maxn];
/*
贪心的想，我合成的这些水晶在已排序数组中一定是相邻的
否则用的能量可以更少，一定不会更劣
如果一个数量可以达到，那么比这个数量低的也一定能达到
可以二分数量
*/
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)S[i]=S[i-1]+a[i];
//	{
//		int ans=LLONG_MAX;
//		for(int i=3;i<=n;i++){
//			int Ans=3*a[i]-(S[i]-S[i-3]);
//			ans=min(ans,Ans);
//		}
//		cout<<ans<<'\n';
//	}
//	for(int i=1;i<=n;i++)cout<<S[i]<<' ';
//	cout<<'\n';
	int l=1,r=n,ans2=1;
	while(l<=r){
		int mid=(l+r)>>1LL;
		int ans=LLONG_MAX;
		for(int i=mid;i<=n;i++){
			int Ans=mid*a[i]-(S[i]-S[i-mid]);
			ans=min(ans,Ans);
		}
		if(ans<=m)l=(ans2=mid)+1;
		else r=mid-1;
	}
	cout<<ans2;
	return 0;
}
//rp++
/*
5 5
1 2 4 8 9
*/
