#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int Case,T,n,d,x[N];
int mi=9e18,cnt;
int sum[N];
void dfs(int u,int t,int sp){
	if(u==t){
		if(sp<mi){
			mi=sp;
			cnt=1;
		}
		else if(sp==mi){
			cnt++;
		}
		return ;
	}
	for(int i=u+1;i<=t;i++){
		if(sum[i]-sum[u]<=d){
			if(sp+1>mi) continue;
			dfs(i,t,sp+1);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>Case>>T;
	if(Case<3){
		while(T--){
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				if(i>1) sum[i]=sum[i-1]+x[i]-x[i-1];
			}
			for(int u=1;u<n;u++){
				for(int v=u+1;v<=n;v++){
					cnt=0,mi=9e18;
					dfs(u,v,0);
					if(cnt==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	else{
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			cout<<0<<'\n';
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
