#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MX=1e6+1;
int n,m,a[MX],s[MX];
inline bool check(int l,int r){
	return a[r]*(r-l+1)-s[r]+s[l-1]<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	int mn=1e18;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mn=min(mn,a[i]);
	}
	for(int i=1;i<=n;++i){
		a[i]-=mn;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=1,r=i,tmp=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				tmp=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-tmp+1);
	}
	cout<<ans;
	return 0;
}

