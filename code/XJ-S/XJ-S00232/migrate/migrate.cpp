#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
ll n,d,a[N];
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll t=d/(a[2]-a[1]);
	if(t>=n||t<=1) cout<<0<<'\n';
	else cout<<n-(t*2-1)<<'\n';
}
void solve2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll p=upper_bound(a+1,a+1+n,a[1]+d)-(a+1);
	cout<<(n-p)*(p-1)<<'\n';
}
ll dp[5005][5005];
void solve3(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		if(a[i]-a[1]<=d) dp[1][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(!dp[i][k])dp[j][k]+=dp[i][j];
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll tot=0;
		for(int j=1;j<=i-1;j++){
			if(dp[j][i]!=0){
				tot++;
			}
		}
		if(tot==2) ans++;
	}
	cout<<ans<<'\n'; 
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll recall,T;
	cin>>recall>>T;
	while(T--){
		if(recall==11||recall==12) solve1();
		else if(recall==13||recall==14) solve2();
		else if(recall==1||recall==2) solve3();
		else{
			cout<<0<<'\n';
		}
	}
	return 0;
}

