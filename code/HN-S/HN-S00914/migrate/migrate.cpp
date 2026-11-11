#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,m,ans,x[N];
void solve1(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i];
	int d=x[2]-x[1];
	int cnt=m/d;
	cnt=cnt*2-1;
	if(cnt==1) ans=0;
	else ans=n-cnt;
	cout<<ans<<"\n";
	return;
}
void solve2(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x[i];
	int u=1;
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=m&&x[n]-x[i]<=m) u=i;
	}
	int r=n;
	for(int i=u-1;i>=1;i--){
		while(r>u&&x[r]-x[i]>m) r--;
		ans+=n-r;
	}
	cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		if(c==11||c==12) solve1();
		if(c==13||c==14) solve2();
	} 
	return 0;
}

