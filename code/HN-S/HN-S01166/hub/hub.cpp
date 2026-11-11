#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+5;
const int inf=1e18;
int vis[M],res,d[M],flag[M],o[M];
int c,t,n,k,a,b,ans,p[M];
vector<int>v[M];
void check(int now,int fa){
	for(int near:v[now]){
		if(!vis[near]||near==fa){
			continue;
		}
		p[near]=1;
		check(near,now);
	}
}
void bfs(int x){
	memset(flag,0,sizeof(flag));
	d[x]=0;
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int near:v[now]){
			if(flag[near]){
				continue; 
			}
			flag[near]=1;
			d[near]=min(d[near],d[now]+1);
			q.push(near);
		}
	}
}
void dfs(int x){ 
	if(x==k+1){
		memset(p,0,sizeof(p));
		int l=0;
		for(int i=1;i<=k;i++){
			if(!p[o[i]]){
				p[o[i]]=1;
				l++;
				check(o[i],0);
			}
		}
		if(l>2){
			return;
		}
		if(l<=2){
			memset(d,0x3f,sizeof(d));
			res=0;
			for(int i=1;i<=k;i++){
				bfs(o[i]);
			}
			for(int i=1;i<=n;i++){
				res=max(res,d[i]);
			}
			ans=min(ans,res);
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			o[x]=i;
			dfs(x+1);
			vis[i]=0; 
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=inf;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
