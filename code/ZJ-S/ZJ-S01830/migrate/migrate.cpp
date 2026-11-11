#include <bits/stdc++.h>
using namespace std;
#define M 200005
#define ll long long
ll n,x[M],cnt,ns,d,dp[305][305][305];
int c,t;
void dfs(ll now,ll y,int step){
	if(now==y){
		if(step<ns){
			cnt=1;
			ns=step;
		}else if(ns==step){
			cnt++;
		}	
	}else{
		for(int i=now+1;i<=y;i++){
			if(x[i]-x[now]<=d){
				dfs(i,y,step+1);
			}else{
				break;
			}
		}
	}
}
int main(void){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++){	
			for(int j=i+1;j<=n;j++){
				cnt=0,ns=1e9;
				dfs(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}	
		cout<<ans<<"\n";
	}
	return 0;
}
