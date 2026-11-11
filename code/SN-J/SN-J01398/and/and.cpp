#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define pb push_back
const int N=2e5+100;
int n,m;
ll a[N];
ll dp[N];
inline void Solve(){
	cin>>n>>m;
	ll mx=a[1],mmx=-1;
	ll ande=a[1];
	bool v=true;
	vec<int> f;
	f.pb(-1);
	if(a[1]) f.pb(a[1]);
	for(int i=2;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
		if(a[i]<mx&&a[i]>=mmx) mmx=a[i];
		ande&=a[i];
		if(a[i])f.pb(a[i]);
		if(a[i]!=0&&a[i]!=1&&a[i]!=2&&a[i]!=3) v=false;
	}
	if(v){
		sort(a+1,a+1+n,greater<ll>());
		ll pppp=a[1];
		for(int i=2;i<=m;i++){
			pppp&=a[i];
		}
		cout<<pppp<<"\n";
		return;
	}
	if(m==2){
		cout<<(mx&mmx)<<"\n";
		return;
	}
	if(m==1||n==1){
		cout<<mx<<"\n";
		return;
	}else if(m==n){
		cout<<ande<<"\n";
		return;
	}
	dp[1]=mx;
	dp[2]=(mx&mmx);
	dp[0]=0;
	int k=m;0
	for(int i=1;i<=n;i++){
		ll col=dp[i-1]&a[i];
		if(col>dp[i])dp[i]+=col;
		else dp[i]=dp[i-1];
		cout<<col<<"\n";
	}
	cout<<dp[m]<<"\n";
}
/*
5 3
31 3 1 15 7

4 2
3 15 12 12
*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) Solve();
	return 0;
}

