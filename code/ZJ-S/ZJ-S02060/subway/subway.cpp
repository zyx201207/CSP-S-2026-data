#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define f first
using namespace std;
const int N=501;
int c,n,m,d,q,a[N],x[N],y[N],k,f[N][N],bis[N],qq,ee;
bool vis[N];
vector<pii >g[N];
void ff(int k){
	for(int i=1;i<=m;i++) bis[i]=INT_MAX,vis[i]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,k});
	bis[k]=0;
	while(!q.empty()){
		int u=q.top().second,w=q.top().f;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].f,ww=g[u][i].second;
		//cout<<v<<" "<<bis[v]<<" "<<ww<<" "<<bis[u]<<"  ";
			if(bis[v]>ww+bis[u]){
				//cout<<"k";
				bis[v]=ww+bis[u];
				q.push({bis[u]+ww,v});
			}
		}
	}
	//cout<<"     ";
	//for(int i=1;i<=m;i++) cout<<bis[i]<<' ';
	//cout<<endl;
	for(int i=1;i<=m;i++) f[k][i]=bis[i];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);/**/
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		cin>>k;
		for(int j=1;j<=k;j++) cin>>x[j]>>y[j];
		for(int j=1;j<=k;j++){
			for(int p=j+1;p<=k;p++){
				if(p==j) continue;
				//cout<<x[p]<<" "<<x[j]<<endl;
				g[x[p]].push_back({x[j],y[p]+y[j]});
				g[x[j]].push_back({x[p],y[j]+y[p]});
			}
		}
	}
	//cout<<endl;
	for(int i=1;i<=m;i++) ff(i);
	//cout<<endl;
	for(int i=1;i<=q;i++){
		cin>>qq>>ee;
		cout<<f[qq][ee]+a[qq]+a[ee]<<endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
