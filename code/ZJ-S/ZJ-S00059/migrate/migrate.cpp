#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2345678];
ll n;
ll d;
void solveA(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(d>=2*a[2]-2*a[1])cout<<max((a[n]-a[1])/(a[2]-a[1])-(d/(a[2]-a[1]))*2+2,0ll);
	else cout<<0;cout<<"\n";
}
ll ans=0;
ll dp[5099][5099];

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=n-1;j++){
		for(int i=1;i<n;i++){
			if(i+j>n)break;
			dp[i][i+j]=(a[i+j]-a[i]<=d);
			for(int k=1;k<j;k++){
				dp[i][i+j]+=dp[i][i+j-k]*dp[i+j-k][i+j];
			}
		}
	}for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
		//	cout<<dp[i][j]<<" ";
			if(dp[i][j]==2)ans++;
		}
	}cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--)solveA();
	}
	else{
		while(t--)solve();
	}
	return 0;
} 
