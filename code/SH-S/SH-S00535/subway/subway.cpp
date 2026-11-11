#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int from,to,val;
};
struct point{
	int pos,cos;
	bool operator > (const point &b) const{
		return cos>b.cos;
	};
};
int c,n,m,d,q,w[500005],k[505],sumk=0,dis[1000010];
bool vis[1000010];
vector<int> a[500005],t[500005];
vector<node> e[1000010];
void dij(int s){
	for(int i=1;i<=1000000;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	priority_queue<point,vector<point>,greater<point> > q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()){
		point now=q.top();
		q.pop();
		if(vis[now.pos]==1){
			continue;
		}
		vis[now.pos]=1;
		for(int i=0;i<e[now.pos].size();i++){
			if(now.cos+e[now.pos][i].val<dis[e[now.pos][i].to]){
				dis[e[now.pos][i].to]=now.cos+e[now.pos][i].val;
				q.push({e[now.pos][i].to,now.cos+e[now.pos][i].val});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
		sumk+=k[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			e[cnt+j+1].push_back({cnt+j+1,a[i][j]+sumk,t[i][j]});
			e[a[i][j]+sumk].push_back({a[i][j]+sumk,cnt+j+1,t[i][j]});
		}
		for(int j=0;j<k[i]-1;j++){
			e[cnt+j+1].push_back({cnt+j+1,cnt+j+2,0});
			e[cnt+j+2].push_back({cnt+j+2,cnt+j+1,0});
		}
		cnt+=k[i];
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		dij(x+sumk);
		cout << dis[y+sumk]+w[x]+w[y] << "\n";
	}
	
	
	return 0;
} 
