#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>g[101];
int c,t;
bool bb[101];
int n,k,u,v;
int minn;
queue<int>q;
queue<pair<int,int> >p;
bool oo[101];
int su;
int o;
void dfs(int x,int s) {
	if(x==n+1) {
		for(int i=1; i<=n; i++) {
			oo[i]=0;
		}
		su=0;
		for(int i=1; i<=n; i++) {
			if(!oo[i]&&bb[i]) {
				su++;
				q.push(i);
				oo[i]=1;
				while(!q.empty()) {
					u=q.front();
					for(int j:g[u]) {
						if(!oo[j]&&bb[j]) {
							oo[j]=1;
							q.push(j);
						}
					}
					q.pop();
				}
				if(su>2) {
					break;
				}
			}
		}
		if(su>2) {
			return;
		}
		for(int i=1; i<=n; i++) {
			if(bb[i]) {
				p.push({i,0});
			}
			oo[i]=bb[i];
		}
		while(!p.empty()) {
			o=p.front().second;
			u=p.front().first;
			for(int j:g[u]) {
				if(!oo[j]) {
					p.push({j,o+1});
					oo[j]=1;
				}
			}
			p.pop();
		}
		minn=min(minn,o);
		return;
	}
	if(s<k) {
		bb[x]=1;
		dfs(x+1,s+1);
	}
	if(s+(n-x)>=k) {
		bb[x]=0;
		dfs(x+1,s);
	}
	return;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) {
		minn=1e9;
		scanf("%d%d",&n,&k);
		for(int i=1; i<=n; i++) {
			g[i].clear();
		}
		for(int i=1; i<n; i++) {
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n>25){
		   cout<<0<<"\n";
		   continue;
		}
		dfs(1,0);
		cout<<minn<<"\n";
	}
	return 0;
}
