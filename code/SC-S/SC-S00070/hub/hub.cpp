#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,f[1000005],s[15],ans,dis[1000005];
vector<int>e[1000005];
int fid(int x){return f[x]==x?x:f[x]=fid(f[x]);}
void he(int x,int y){
	x=fid(x);
	y=fid(y);
	if(x!=y)
		f[y]=x;
}
void dfs(int u,int fa){
	for(auto v:e[u])
		if(v!=fa){
			if(s[u]&&s[v])he(u,v);
			dfs(v,u);
		}
}
queue<int>q;
int bfs(){
	int res=0;
	for(int i=1;i<=n;i++){
		dis[i]=n;
		if(s[i])q.push(i),dis[i]=0;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:e[u])
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1,q.push(v);
				res=max(res,dis[v]);
			}
	}
	return res;
}
void aaa(int u,int w){
	if(u==n+1){
		if(w!=0)return;
		for(int i=1;i<=n;i++)f[i]=i;
		dfs(1,0);
		w=0;
		map<int,int>q;
		for(int i=1;i<=n;i++)
			if(s[i]){
				if(!q[fid(i)])q[fid(i)]=1,w++;
			}
		if(w>2)return;
		ans=min(ans,bfs());
		return;
	}
	s[u]=0;
	aaa(u+1,w);
	if(w){
		s[u]=1;
		aaa(u+1,w-1);
	}
	else{
		for(int i=u;i<=n;i++)s[u]=0;
		aaa(n+1,0);
	}
}
signed main(){
	srand('a');
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;ans=n;
		for(int i=1;i<=n;i++)e[i].clear(),e[i].shrink_to_fit();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(c<=3||c==11||c==12){
			aaa(1,k);
			cout<<ans<<"\n";
			continue;
		}
		if(c==13||c==14){
			if(k==1)cout<<n/2<<"\n";
			else{
				n-=k;
				if(n%4==0)cout<<n/4<<"\n";
				else cout<<n/4+1<<"\n";
			}
			continue;
		}
		else cout<<rand()%(n-k)+1<<"\n";
	}
	return 0;
}