#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,k;
vector<int>to[1000006];
int dis[1003][1003];
bool v[1000006];
void bfs(int s){
	queue<int>q;
	for(int i=1;i<=n;i++){
		dis[s][i]=0x3f3f3f3f3f3f3f3f;
		v[i]=0;
	}
	dis[s][s]=0;
	v[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int y:to[x]){
			if(v[y])continue;
			if(dis[s][x]+1<dis[s][y]){
				dis[s][y]=dis[s][x]+1;
				v[y]=1;
				q.push(y);
			} 
		} 
	}
}
int p[1000006];
int find(int x){
	if(p[x]==x)return x;
	return p[x]==find(p[x]);
}
bool ch[1000006];
int cc[1000006];
int ans;
int op[1003][1003];
void dfs(int id=1,int od=0){
	if(id>k){
		int ct=0;
		if(k>2){
			for(int i=1;i<=k;i++){
				ct+=p[cc[i]]==cc[i];
			}
		}
		if(ct>2)return;
		int mx=0;
		for(int i=1;i<=n;i++){
			int mn=0x3f3f3f3f3f3f3f3f;
			if(ch[i]){
				continue;
			}
			for(int j=1;j<=k;j++){
				mn=min(mn,dis[i][cc[j]]);
			}
			mx=max(mx,mn);
		}
		ans=min(ans,mx);
		return;
	}
	if(k>2){
		for(int i=1;i<=n;i++){
			op[id][i]=p[i];
		}
		for(int i=od+1;i<=n;i++){
			for(int y:to[i]){
				if(y>i)break;
				if(!ch[y])continue;
				p[find(y)]=i;
			}
			ch[i]=1;
			cc[id]=i;
			dfs(id+1,i);
			ch[i]=0;
			for(int j=1;j<=n;j++){
				p[j]=op[id][j];
			}
		}
	}
	else{
		for(int i=od+1;i<=n;i++){
			ch[i]=1;
			cc[id]=i;
			dfs(id+1,i);
			ch[i]=0;	
		}
	}
		
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0x3f3f3f3f3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			p[i]=i;
		}
		dfs();
		cout<<ans<<"\n";
		for(int i=0;i<=n;i++)to[i].clear();
	}
	return 0; 
}

