#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
int n,m,a[N];
const inline bool pd(const int &x){
	int s=0,ans=1e18,sum=0;
	for(int i=1;i<x;++i)sum+=a[i];
	for(int i=x;i<=n;++i){
		sum+=a[i]-a[i-x];
		ans=min(ans,a[i]*x-sum);
	}return ans<=m;
}signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=n;
	while(l<r){
		const int mid=(l+r+1)>>1;
		if(pd(mid))l=mid;
		else r=mid-1;
	}cout<<l;
	return 0;
}
