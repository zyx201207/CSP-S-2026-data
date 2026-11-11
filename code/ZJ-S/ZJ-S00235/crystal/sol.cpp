/*
20261031
T   W   D
1   5   5
	2   1
W   15:22
D   15:24
F   15:25
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],s[N];
void ATRI()
{
	int n;ll m;cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int l=1,r=i,res=-1;
		auto chk=[&](int x){return 1ll*x*a[i]-(s[i]-s[i-x])<=m;};
		while(l<=r){int mid=l+r>>1;if(chk(mid))res=mid,l=mid+1;else r=mid-1;}
		ans=max(ans,res);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ATRI();
	return 0;
}