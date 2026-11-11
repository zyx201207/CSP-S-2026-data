#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int N=2e6+5;
const int INF=1e18;
int O,T,n,d,a[N],lst[N],ans;
pii dp[N];
inline void solve1(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		lst[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
	}
	for(int i=1;i<=n;i++){
		fill(dp+i,dp+n+1,make_pair(INF,0));
		dp[i]={0,1};
		for(int j=i+1;j<=n;j++){
			for(int k=max(i,lst[j]);k<j;k++){
				if(dp[j].sec>2)break;
				if(dp[j].fir>dp[k].fir+1){
					dp[j].fir=dp[k].fir+1;
					dp[j].sec=dp[k].sec;
				}
				else if(dp[j].fir==dp[k].fir+1){
					dp[j].sec+=dp[k].sec;
				}
				else{
					break;
				}
			}
			if(dp[j].sec==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
inline void solve2(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		lst[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
	}
	int i=1;
	fill(dp+i,dp+n+1,make_pair(INF,0));
	dp[i]={0,1};
	for(int j=i+1;j<=n;j++){
		for(int k=max(i,lst[j]);k<j;k++){
			if(dp[j].sec>2)break;
			if(dp[j].fir>dp[k].fir+1){
				dp[j].fir=dp[k].fir+1;
				dp[j].sec=dp[k].sec;
			}
			else if(dp[j].fir==dp[k].fir+1){
				dp[j].sec+=dp[k].sec;
			}
			else{
				break;
			}
		}
		if(dp[j].sec==2){
			ans+=(n-j+1);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>O>>T;
	if(O<=10){
		while(T--){
			solve1();
		}
	}
	else if(O<=12){
		while(T--){
			solve2();
		}
	}
	else{
		while(T--){
			solve1();
		}
	}
}
/*
16:08 40pts
16:17 48pts
*/