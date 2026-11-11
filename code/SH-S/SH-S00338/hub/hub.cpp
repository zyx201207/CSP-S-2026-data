#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int maxs;
bool book[N],st[N];
vector<int> g[N];
void dfs1(int u,int fa){
	st[u]=0;
	for(auto v:g[u]){
		if(v==fa) continue;
		if(st[v]){
			dfs1(v,u);
		}
	}
}
void dfs2(int u,int fa,int s){
	if(book[u]){
		maxs=max(maxs,s);
		return;
	}
	for(auto v:g[u]){
		if(v==fa) continue;
		dfs2(v,u,s+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t,n,k,x,y,cnt,mins;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		mins=INT_MAX;
		for(int i=0;i<1<<n;i++){
			cnt=0;
			for(int j=0;j<n;j++){
				book[j+1]=0;
				st[j+1]=0;
				if(i>>j&1){
					book[j+1]=1;
					st[j+1]=1;
					cnt++;
				}
			}
			if(cnt!=k) continue;
			cnt=0;
			for(int j=1;j<=n;j++){
				if(st[j]){
					cnt++;
					dfs1(j,-1);
				}
			}
			if(cnt>2) continue;
			maxs=0;
			for(int j=1;j<=n;j++){
				if(!book[j]) dfs2(j,-1,0);
			}
			mins=min(mins,maxs);
		}
		cout<<mins<<"\n";
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
	}
	return 0;
}

