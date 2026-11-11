#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
struct node{
	int x,y;
};
int w[N];
vector<node> a[N];
int c,n,m,d,q;
node l[N];
int vis[N],cost[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back({x,y});
		}
	}
	if(c==7||c==8||c==9||c==10||c==11){	
		while(q--){
			int x,y;
			cin>>x>>y;
			memset(vis,0,sizeof(vis));
			memset(cost,0x3f,sizeof(cost));
			vis[x]=1;
			cost[x]=0;
			pq.push({0,1});
			while(!pq.empty()){
				pair <int,int> p=pq.top();
				pq.pop();
				int u=p.second;
				for(int i=0;i<a[u].size();i++){
					node z=a[u][i];
					if(cost[z.x]>cost[u]+z.y){
						cost[z.x]=cost[u]+z.y;
						vis[z.x]=1;
						pq.push({cost[z.x],z.x});
					}
				}
			}
			cout<<cost[y]+w[x]+w[y];
		}
	}
	return 0;
}

