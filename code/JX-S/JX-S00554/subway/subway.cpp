#include<bits/stdc++.h>
using namespace std;
const int N=510;
int m,n,c,d,q;
int w[N],k[N],a[N][N],t[N][N],x,y,dist[N];
bool ct[N];
struct edge{
	int to,w;
};
struct node{
	int id,to,w;
};
vector<node> p[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
			p[i].push_back({j,a[i][j],t[i][j]});
		}
    }
    for(int i=1;i<=n;i++)
    for(int i=1;i<=q;i++){
		
        cin>>x>>y;
        queue<node> q;
		q.push({x,0});
		while(q.size()){
			node u=q.front();
			q.pop();
			for(int i=1;i<=n;i++)
				for(node v:p[i])
					if(dist[v.to]+v.w<dist[u.to]){
						dist[u.to]=dist[v.to]+v.w;
						q.push({v.to,u.w});
					}
		}
		cout<<dist[y]<<'\n';
		memset(dist,0,sizeof(dist));
    }
    return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
* */
