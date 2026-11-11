#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int N=1e6+10;
auto getmax=[](auto &a,auto b){a=max(a,b);};
auto getmin=[](auto &a,auto b){a=min(a,b);};

int dis[N],dp[N];
vector<int> g[N];
void dfs1(int u,int fa){
	dis[u]=dp[u]=0;
	for(auto v:g[u]){
		if(v==fa) continue;
		dfs1(v,u);
		getmax(dp[u],dp[v]);
		getmax(dp[u],dis[u]+dis[v]+1);
		getmax(dis[u],dis[v]+1);
	}
}
int c,T,n,k,mxlen,id;
void dfs2(int u,int fa,int up,int len){
	vector<int> vec;
	for(auto v:g[u]) vec.push_back((v==fa? up:dp[v]));
	int p=max_element(vec.begin(),vec.end())-vec.begin();
	vec[p]=(vec[p]+1)/2;
	int mx=*max_element(vec.begin(),vec.end());
	if(mx<mxlen) mxlen=mx, id=u;
	
	int siz=g[u].size();
	vector<int> pre(siz+2),suf(siz+2),l(siz+2),r(siz+2);
	for(int i=1; i<=siz; i++){
		int v=g[u][i-1],nw=(v==fa? len:dis[v]);
		pre[i]=max({pre[i-1],(v==fa? up:dp[v]),l[i-1]+nw+1});
		l[i]=max(l[i-1],nw+1);
	}
	for(int i=siz; i>=1; i--){
		int v=g[u][i-1],nw=(v==fa? len:dis[v]);
		suf[i]=max({suf[i+1],(v==fa? up:dp[v]),r[i+1]+nw+1});
		r[i]=max(r[i+1],nw+1);
	}
	for(int i=1; i<=siz; i++){
		int v=g[u][i-1];
		if(v==fa) continue;
		int nw=max({pre[i-1],suf[i+1],l[i-1]+r[i+1]});
		dfs2(v,u,nw,max(l[i-1],r[i+1]));
	}
}
bool read(){
	bool flag=n&1;
	int m=n/2;
	for(int i=1,u,v; i<=n-1; i++){
		cin>>u>>v;
		if(i<=m&&(u!=i||v!=i+1)) flag=0;
		if(i>m&&(u!=i-m||v!=i+1)) flag=0;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	return flag;
}
int vis[N];
void dfs3(int u){
	vis[u]=0;
	for(auto v:g[u])
		if(vis[v]) dfs3(v);
}
void dfs4(int u,int fa){
	for(auto v:g[u])
		if(v!=fa) getmin(dis[v],dis[u]+1), dfs4(v,u);
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1; i<=n; i++) g[i].clear();
		if(read()){
			int ans=1e9;
			if(k==n) cout<<0<<endl;
			else if(k>=n/2) cout<<1<<endl;
			else{
				int sum=n/2+4-k;
				cout<<sum<<endl;
				for(int a=max(1,sum/4-5); a<=sum/4+5; a++)
					for(int b=max(1,sum/4-5); b<=sum/4+5; b++)
						for(int c=max(1,sum/4-5); c<=sum/4+5; c++)
							if(n/2-k-a-c+2>=0)
//								cout<<a+b*2+c<<" "<<(sum+!((n/2-k-a-c+2)&1))<<endl;
							if(a+b*2+c==sum+!((n/2-k-a-c+2)&1)+1)
								getmin(ans,max({a,b,c}));
				cout<<ans<<endl;
			}
		}else if(n<=100){
			int cnt=20000000/n/n,ans=1e9;
			vector<int> vec(n);
			iota(vec.begin(),vec.end(),1);
			mt19937 rd(time(0));
			while(cnt--){
				shuffle(vec.begin(),vec.end(),rd);
				for(int i=0; i<k; i++) vis[vec[i]]=1;
				int tot=0;
				for(int i=1; i<=n; i++) if(vis[i]) dfs3(i), tot++;
				if(tot>2) continue;
				for(int i=1; i<=n; i++) dis[i]=1e9;
				for(int i=0; i<k; i++) dis[vec[i]]=0, dfs4(vec[i],0);
				getmin(ans,*max_element(dis+1,dis+n+1));	
			}
			cout<<ans<<endl;
		}else{
			dfs1(1,0), mxlen=1e9, dfs2(1,0,0,0);
			cout<<mxlen<<endl;	
		}
	}
	
	return 0;
}