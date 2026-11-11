#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,t,n,d,ans;
int a[200005];
int len[200005];
int num[200005];
vector<int>g[200005];
void bfs(int s){
	queue<int>q;
	for(int i=1;i<=n;i++){
		len[i]=2e18;
		num[i]=0;
	}
	len[s]=0;
	num[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(len[u]+1<len[v]){
				len[v]=len[u]+1;
				num[v]=num[u];
				q.push(v);
			}
			else if(len[u]+1==len[v]){
				num[v]+=num[u];
				q.push(v);
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(num[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
	}
	return 0;
}
