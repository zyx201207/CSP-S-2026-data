#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
using namespace std;
const int N = 5e5 + 10 , inf = 0x3f3f3f3f3f3f3f3f ;
int w[N],dt[N],tim[N];
int d[1010][1010];
bool tg[1010];
vector<pii>t[N];
vector<int>g[N];
void dij(int s){

	memset(tg,0,sizeof tg);
	priority_queue< pii,vector<pii>,greater< pii > >q;
	q.push({0,s});
	d[s][s]=0;
	while(q.size()){
		int u=q.top().se;
		q.pop();
		if(tg[u]) continue;
		tg[u]=1;
		for(auto v:g[u]){	
			for(auto o:t[u]){
				for(auto l:t[v]){
					if(l.fi==o.fi and d[s][v]>d[s][u]+l.se+o.se){
						d[s][v]=d[s][u]+l.se+o.se;
						q.push({d[s][v],v});
					}
		
				}
			}
		}
	}
}

signed main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T,n,m,d1,q;

	cin>>T>>n>>m>>d1>>q;
	for(int i=1;i<=m;i++) cin>>w[i]; 
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>dt[j]>>tim[j];
			t[dt[j]].pb({i,tim[j]}); 	
		}
		for(int j=1;j<=k;j++){
			for(int o=j+1;o<=k;o++){
				g[dt[j]].pb(dt[o]);
				g[dt[o]].pb(dt[j]);
			}
		}
	}	
	for(int i=1;i<=m;i++){
	 	for(int j=1;j<=m;j++) d[i][j]=inf; 
	}
	for(int i=1;i<=m;i++) dij(i);
	
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++) cout<<d[i][j]<<" ";
//		cout<<endl;
//	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		if(x>y) swap(x,y);
		cout<<w[x]+w[y]+d[x][y]<<endl;
	}

	return 0;
}
/*

Oct31==Dec25?

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
