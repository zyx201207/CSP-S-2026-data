#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int MAXN=5e5+10;
int T=1;
int n,m;
int a[MAXN];
int pre[MAXN];
int ans;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
	for(int i=2;i<=n;++i){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(pre[i]-pre[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		if(l<i) ans=max(ans,i-l+1);
	}
	cout<<ans;
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//cout<<fixed<<setprecision(2);
	//cin>>T;
	while(T--) solve();
}
