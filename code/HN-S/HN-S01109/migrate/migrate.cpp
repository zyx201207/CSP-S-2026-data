#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
const ll INF=1e18+10;
int c,t,n,d;
ll a[N];
namespace subtack1{
	ll dis[15]={},sum[15]={},ans=0;
	void dfs_1(int x,ll step){
		dis[x]=min(dis[x],step);
		if(x==n) return ;
		for(int i=x+1;i<=n;i++){
			if(a[i]-a[x]<=d){
				dfs_1(i,step+1);
			}else{
				break;
			}
		}
	}
	void dfs_2(int x,int step){
		if(step==dis[x]) sum[x]++;
		if(x==n) return ;
		for(int i=x+1;i<=n;i++){
			if(a[i]-a[x]<=d){
				dfs_2(i,step+1);
			}else{
				break;
			}
		}
	}
	void solve(){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[j]=INF;
				sum[j]=0;
			}
			dfs_1(i,0);
			dfs_2(i,0);
			for(int j=1;j<=n;j++){
				if(sum[j]==2){
					ans++;
					//cout<<i<<' ';
				}
			}
			
		}
		cout<<ans<<'\n';
	}
}
namespace subtack2{
	
	void solve(){
		
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c<=2) subtack1::solve();
		else subtack2::solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
