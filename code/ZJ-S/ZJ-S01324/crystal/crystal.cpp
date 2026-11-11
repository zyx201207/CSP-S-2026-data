#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int n,m,a[N],s[N];
bool f(int x){
	int res=1e18;
	for(int i=1;i+x-1<=n;++i){
		int j=i+x-1;
		res=min(res,a[j]*(j-1-i+1)-s[j-1]+s[i-1]);
//		cout<<i<<' '<<(k-1-i+1)*md- s[k-1]+s[i-1] +s[j]-s[k] -(j-(k+1)+1)*md<<'\n';
	}
//	cout<<x<<' '<<res<<'\n';
	return res<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(f(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}

