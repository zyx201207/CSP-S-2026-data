#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int M=5e5+500;
struct ovo{
	int v,w;
};
int c,n,m,d,q,cnt[M],vis[M],dis[M],a[M],t,ans;
vector<ovo>vec[M+500];
void solu(int x){
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	memset(dis,63,sizeof(dis));
	queue<int>q;
	q.push(x);vis[x]=1;dis[x]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<vec[u].size();i++){
			int v=vec[u][i].v,w=vec[u][i].w;
			if(dis[v]>=dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					cnt[v]=1;
					vis[v]=1;
					q.push(v);
				}
				else cnt[v]++;
			}
		}
	}
	for(int i=1;i<=n;i++)if(cnt[i]==2)ans++;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)vec[i].clear();
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>0&&a[i]-a[j]<=d;j--)
				vec[j].push_back({i,1});
		}
		for(int i=1;i<=n;i++)solu(i);
		cout<<ans<<'\n';
	}
	
	return 0;
} 
