#include<bits/stdc++.h>
#define int long long// focus!!
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N];
void ini(){
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
}
int cal(int l,int r){//calculate r
	int p=(r-l+1)*a[r]-(s[r]-s[l-1]);
	return p;
}
int ef(int now){
	int l=1,r=now;
	while(l<r){
		int mid=(l+r)>>1;
		if(cal(mid,now)<=m)r=mid;//1
		else l=mid+1;//0
	}
	return l;
}
void solve(){
	ini();
	int ans=1;
	for(int i=1;i<=n;++i){
		int _l=ef(i);
		ans=max(ans,i-_l+1);
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	solve();
	return 0;
}