#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],ans;
int s[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=i,mid,u=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(s[i]-s[mid-1]+m>=a[i]*(i-mid+1)) r=mid-1,u=mid;
			else l=mid+1;
		}
		ans=max(ans,i-u+1);
	}cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(0),cin.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
/*
I think this problem is easier than Minecraft Crystal PVP.
估分 100+100+48+25=273
希望不挂分

RP++ 
*/
