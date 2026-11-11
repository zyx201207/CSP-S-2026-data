#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=2000010;
ll n,d,a[MAXN],dist[5010][5010],dp[5010][5010];
void solve(ll test){
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(d==1||n<=3){
		cout<<0<<'\n';
		return;
	}
	if(test<=10){
		ll ans=0;
		for(int i=0;i<n;i++){
			dist[i][i]=0;dp[i][i]=1;
			for(int j=i+1;j<n;j++){
				if(a[j]-a[i]>d){
					dist[i][j]=114514;
					dp[i][j]=0;
				}else{
					dist[i][j]=1;
					dp[i][j]=1;
				}
			}
		}
		for(int i=0;i<n-2;i++){
			for(int k=i+1;k<n-1;k++){
				for(int j=k+1;j<n;j++){
					if(dist[i][j]>dist[i][k]+dist[k][j]){
						dist[i][j]=dist[i][k]+dist[k][j];
						dp[i][j]=min(3ll,dp[i][k]*dp[k][j]);
					}else if(dist[i][j]==dist[i][k]+dist[k][j]){
						dp[i][j]=min(3ll,dp[i][j]+dp[i][k]*dp[k][j]);
					}
				}
			}
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(dp[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
		return;
	}
	if(11<=test&&test<=12){
		ll __mY_DeLTa_VaLuE___=a[1]-a[0],_M_Y_D_I_S_T_=d/__mY_DeLTa_VaLuE___;
		if(_M_Y_D_I_S_T_<=1){
			cout<<0<<'\n';
			return;
		}
		cout<<max(0ll,n+1-_M_Y_D_I_S_T_*2)<<'\n';
		return;
	}
	if(13<=test&&test<=14){
		return;
	}
	if(15<=test){
		return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		solve(c);
	}
	return 0;
}