#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,d,c,t,a[N],vis[N],ans=0;
vector<int> v[N];
void bfs(int s,int t){
	queue<pair<int,int> > q;
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	q.push({s,0});
	int cnt=0,mini=1e9;
	while(q.size()){
		int u=q.front().first,st=q.front().second;q.pop();
		if(u==t&&st<=mini){
			cnt++;
			mini=st;
		}
		if(st>mini) break;
		for(auto j:v[u]){
			if(vis[j]) continue;
			q.push({j,st+1});
		}
	}
	if(cnt==2){
		ans++;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				bfs(i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
