#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=2e6+10;
int C,T;
int n,k,ans=1e9,maxn,minn;
int lj[N],tp;
bool vs[N];
bool jy[N];
bool vss[N];
vector<int>g[N];
void fll(int x){
	jy[x]=1;
	for(int i=0;i<g[x].size();i++){
		if(vs[g[x][i]]&&!jy[g[x][i]]){
			jy[g[x][i]]=1;
			fll(g[x][i]);
		}
	}
}
void tq(int x,int t){
	if(vs[x]==1){
		minn=min(minn,t);
		return ;
	}
	for(int i=0;i<g[x].size();i++){
		if(!vss[g[x][i]]){
			vss[g[x][i]]=1;
			tq(g[x][i],t+1);
			vss[g[x][i]]=0;
		}
	} 
}
void dfs(int x){
	if(tp>k) return ;
	if(tp==k){
		int cnt=0;
		for(int i=1;i<=n;i++) jy[i]=0;
		for(int i=1;i<=tp;i++){
			if(!jy[i]){
				cnt++;
				fll(i);
			}
		}
		if(cnt<=2){	
			maxn=0;
			for(int i=1;i<=n;i++){
				if(!vs[i]){
					minn=1e9;	
					for(int j=1;j<=n;j++) vss[j]=0;
					vss[i]=1;
					tq(i,0);
					maxn=max(maxn,minn);
				}
			}
			ans=min(maxn,ans);
		}
		return ;
	}
	lj[++tp]=x;
	vs[x]=1;
	dfs(x+1);
	tp--;
	vs[x]=0;
	dfs(x+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		tp=0; 
		ans=1e9;
		dfs(1);
		cout<<ans<<'\n';
//		cout<<clock()<<"ms";
	}
	return 0;
}
