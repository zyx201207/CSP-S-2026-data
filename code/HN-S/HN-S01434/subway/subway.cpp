#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
struct node{
	int x,w,f,s;
};
int c,n,m,d,q,w[N],k[505],v[N],t[505][100005],o[505][100005],ans,r,a;
vector<int> g[N],l[505];
void bfs(int x,int y){
	
	queue<node> q;
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			o[i][j]=0x7fffffff;
		}
	}
	
	for(int i=1;i<=g[x].size();i++){
		o[g[x][i]][x]=t[g[x][i]][x];
		q.push((node){x,t[g[x][i]][x],-1,g[x][i]});
	}
	
	while(!q.empty()){
		node h=q.front();
		cout<<h.x<<endl;
		if(h.x==y){
			ans=max(ans,h.w);
		}
		if(h.f!=h.x){
			for(int i=1;i<=g[h.x].size();i++){
				if(h.s!=g[h.x][i] && o[g[h.x][i]][h.x]>h.w+t[g[h.x][i]][h.x]+t[h.s][h.x]){
					q.push((node){h.x,h.w+t[g[h.x][i]][h.x]+t[h.s][h.x],h.x,g[h.x][i]});
				}
			}
		}
		for(int i=1;i<=l[h.s].size();i++){
			if(h.x!=l[h.s][i]){
				q.push((node){l[h.s][i],h.w,h.x,h.s});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int p,b;
			cin>>p>>b;
			t[i][p]=b;
			g[p].push_back(i);
			if(g[p].size()>1){
				l[i].push_back(p);
				if(v[p]!=0){
					l[v[p]].push_back(p);
					v[p]=0;
				}
			}
			else if(g[p].size()==1){
				v[p]=i;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r>>a;cout<<1;
		//ans=0x7fffffff;
		bfs(r,a);
	}
	cout<<ans;
    return 0;
}

