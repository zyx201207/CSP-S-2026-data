#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
int w[500005];
int k,a,l,t[5005][500005];
bool have[5005][500005];
int x,y;
struct edge{
    int v,di;
};
vector<edge> e[500005];
void dosth(int x,int y){
	int dis[500005];
	int vis[500005];
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
    int sum=0;
    sum=w[x]+w[y];
    priority_queue<int,vector<int>,greater<>> q;
    q.push(x);
    while(!q.empty()){
    	int u=q.top();
    	q.pop();
	    for(auto k:e[u]){
			int v=k.v;
			int di=k.di;
			if(vis[v]){
				continue;
			}
			vis[v]=1;
			if(dis[v]>dis[u]+di){
				dis[v]=dis[u]+d;
				q.push(v);
			}
		}
	}
	sum+=dis[y];
	cout<<sum<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
        cin>>k;
        l=0;
        for(int j=1;j<=k;j++){
            cin>>a;
            cin>>t[i][a];
            have[i][a]=1;
            e[l].push_back({a,t[i][a]});
            e[a].push_back({l,t[i][a]});
            l=a;
        }
    }

    for(int i=1;i<=q;i++){
        cin>>x>>y;
        dosth(x,y);
    }
	return 0;
}
