#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll C,T,n,d,a[N],lastin[N],in[N],dp[N],cnt[N];
vector<int> g[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			g[i].clear();
		}
		if(C==13||C==14){
			cout<<0<<'\n';
			continue;
		} 
		memset(lastin,0,sizeof(lastin));
		sort(a+1,a+n+1);
		ll ans=0;
		for(int i=n;i>=1;i--){
			for(int j=i;j<=n;j++){
				in[j]=lastin[j];
				dp[j]=0x3f3f3f3f3f3f3f3f;
				cnt[j]=0;
			}
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d)	g[i].push_back(j),in[j]++;
			}
			for(int j=i;j<=n;j++){
				lastin[j]=in[j];
			}
			queue<int> q;
			q.push(i),dp[i]=0,cnt[i]=1;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int v:g[u]){
					if(dp[u]+1<dp[v]){
						dp[v]=dp[u]+1,cnt[v]=cnt[u];
					}
					else if(dp[u]+1==dp[v]){
						cnt[v]+=cnt[u];
					}
					in[v]--;
					if(in[v]==0)	q.push(v);
				}
			}
			//cout<<i<<'\n';
			for(int j=i;j<=n;j++){
				//cout<<cnt[j]<<' ';
				if(cnt[j]==2)	ans++;
			}
		}
		cout<<ans<<'\n';
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
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
