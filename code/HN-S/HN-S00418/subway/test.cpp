#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0)); 
const int N=2e6+7;
int c,t;
int n;
long long way[N];
long long x[N],d;
long long dp[5555];
void solve1(){
	for(int i=1;i<=n;i++){
		dp[i]=LONG_LONG_MAX;
		way[i]=0;
	}
	dp[1]=0;
	way[1]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(1ll*(long long)(x[j]-x[i])<=d){
//				if(dp[j]>dp[i]+1){
//					way[j]=way[i];
//				}
//				else if(dp[j]==dp[i]+1){
//					way[j]+=way[i];
//				}
//				else continue;
				dp[j]=min(dp[j],dp[i]+1);
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(1ll*(long long)(x[j]-x[i])<=d){
				if(dp[j]!=dp[i]+1) continue;
				way[j]=way[j]+way[i];
				cout<<i<<" "<<"jump to"<<j<<" "<<way[j]<<" "<<way[i]<<'\n';
			}
		}
	}
	long long total=0;
	for(int i=1;i<=n;i++){
		if(way[i]==2){
			total++;
		}
		cout<<dp[i]<<" ";
	}
	cout<<'\n';
	for(int i=1;i<=n;i++){
		cout<<way[i]<<" ";
	}
	cout<<'\n';
	cout<<total<<'\n';
}
void solve2(){
	cout<<rnd()%n<<'\n';
}
signed main(){
//	freopen("sample.in","r",stdin);
//	freopen("sample.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>c>>t;
	if(c<=10){
		
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			solve1();
		}
	}
	else{
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			solve2();
		}
	}
	
	
	
	return 0;
}
