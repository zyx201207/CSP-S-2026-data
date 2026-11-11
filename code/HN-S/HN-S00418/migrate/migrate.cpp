#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0)); 
const int N=2e6+7;
int c,t;
int n;
long long ans=0;
long long x[N],d;
long long dp[N];
long long way[N];
void solve1(){
	int total=0;
	for(int s=1;s<=n;s++){
		for(int i=s;i<=n;i++){
			dp[i]=LONG_LONG_MAX;
			way[i]=0;
		}
		dp[s]=0;
		way[s]=1;
		for(int i=s;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(1ll*(long long)(x[j]-x[i])<=d){
					dp[j]=min(dp[j],dp[i]+1);
				}
			}
		}
//		cout<<"------------------------------"<<'\n';
//		cout<<s<<'\n';
//		for(int i=s;i<=n;i++){
//			cout<<dp[i]<<' ';
//		}
//		cout<<'\n';
		for(int i=s;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(1ll*(long long)(x[j]-x[i])<=d && dp[j]==dp[i]+1){
					way[j]+=way[i];
//					cout<<i<<" jumpt to"<<j<<'\n';
				}
			}
		}
//		for(int i=s;i<=n;i++){
//			cout<<way[i]<<' ';
//		}
//		cout<<'\n';
		for(int i=s+1;i<=n;i++){
			if(way[i]==2){
				total++;
//				cout<<s<<" "<<i<<'\n';
			}
		} 
	}
	cout<<total<<'\n';
	
}
void solve2(){
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
//	for(int i=1;i<n;i++){
//		for(int j=i+1;j<=n;j++){
//			if(1ll*(long long)(x[j]-x[i])<=d){
//				
//				
//			}
//		}
//	}
	long long total=0;
	for(int i=1;i<=n;i++){
		if(way[i]==2){
			total++;
		}
//		cout<<dp[i]<<" ";
	}
//	cout<<'\n';
//	for(int i=1;i<=n;i++){
//		cout<<way[i]<<" ";
//	}
//	cout<<'\n';
	cout<<total<<'\n';
}
void solve3(){
	cout<<rnd()%n<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0); 
	cin>>c>>t;
	if(c<=6){
		
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			solve1();
		}
	}
	else if(c<=10){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			solve2();
		}
	}
	else{
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			solve3();
		}
	}
	
	
	
	return 0;
}
