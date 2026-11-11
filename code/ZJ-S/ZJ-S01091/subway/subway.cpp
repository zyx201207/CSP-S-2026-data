#include<bits/stdc++.h>

using namespace std;

const int M=5e5+3,N=505;

int c,n,m,d,q;
int w[M],k[N],t[N][M];
set<int> s[N];
vector<pair<int,int> > v[M];
bool vis[M];
int ex;
long long mi=0x3f3f3f3f;
set<int> ss[M];

void dfs(int now,int nid,long long sum){
	if(sum>=mi) return;
	if(now==ex){
		mi=min(mi,sum);
		return;
	}
	for(auto it:v[now]){
		if(vis[it.first]) continue;
		vis[it.first]=1;
		if(it.second!=nid) dfs(it.first,it.second,sum+t[it.second][it.first]+t[nid][it.first]);
		else dfs(it.first,it.second,sum+t[it.second][it.first]);
		vis[it.first]=0;
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int aij,tij;
			cin>>aij>>t[i][j];
			s[i].insert(aij);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(auto it:s[i]){
			for(auto it2:s[i]){
				if(it!=it2) v[it].push_back({it2,i});
			}
			ss[it].insert(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y; 
		mi=0x3f3f3f3f;
		ex=y;
		vis[x]=1;
		for(auto itr:ss[x]){
			dfs(x,itr,w[x]+w[y]+t[itr][x]);
		}		
		vis[x]=0;
		cout<<mi<<"\n";
	}
	return 0;
}
