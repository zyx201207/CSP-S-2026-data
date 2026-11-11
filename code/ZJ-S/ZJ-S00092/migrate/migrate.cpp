#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10,INF=8e18;
ll x[N];
ll n,d;
ll ans;
vector<ll>an;
void solve1(){
	ans=0;
	cin>>n>>d;
	vector<vector<vector<ll>>>dp(n+2,vector<vector<ll>>(n+2,vector<ll>(2,INF)));
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int p=1;
	if(x[n]-x[1]<=d){
		an.push_back(0);
		return;
	}
	while(x[p]-x[1]<=d&&p<=n){
		p++;
		if(x[p]-x[1]>d){
			break;
		}
		for(int i=1;i<p;i++){
			dp[i][p][0]=1;
			dp[i][p][1]=1;
		}
	}
	int last=1,div=1;
	for(;p<=n;p++){
		while(last<=p&&x[p]-x[last]>d)last++;
		if(last==p){
			div=p;
//			cout<<"----------------\n";
			while(x[p]-x[last]<=d&&p<=n){
				p++;
				if(x[p]-x[last]>d){
					break;
				}
				for(int i=last;i<p;i++){
					dp[i][p][0]=1;
					dp[i][p][1]=1;
					
				}
			}
			while(last<=p&&x[p]-x[last]>d)last++;
		}
		for(int i=last;i<p;i++){
			dp[i][p][0]=1;
			dp[i][p][1]=1;
		}
		for(int i=last-1;i>=div;i--){
			 ll mi=INF-1,cnt=0;
			 for(int k=last;k<p;k++){
			 	if(dp[i][k][0]<mi){
			 		cnt=dp[i][k][1];
			 		mi=dp[i][k][0];
			 		if(dp[i][p][0]>mi+1)dp[i][p][0]=mi+1,dp[i][p][1]=dp[i][k][1];
			 		else if(dp[i][p][0]==mi+1)dp[i][p][1]+=dp[i][k][1];
				}
				else{
					if(dp[i][k][0]==mi)cnt+=dp[i][k][1],dp[i][p][1]+=dp[i][k][1];
				}
				
			 }
			 if(cnt==2){
			 	ans++;
//			 	cout<<i<<' '<<p<<' '<<dp[1][7][1]<<' '<<dp[1][6][1]<<' '<<mi<<'\n';
			 }
//			 if(i==2&&p==5){
//			 	cout<<last<<'\n';
//			 }
		}
	}
	an.push_back(ans);
	dp.clear();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T,c;
	cin>>c>>T;
	for(int i=1;i<=T;i++){
		solve1();
	}
	for(int i=1;i<=T;i++){
		cout<<an[i-1]<<'\n';
	}
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/