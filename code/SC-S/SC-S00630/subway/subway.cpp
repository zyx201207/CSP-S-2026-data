#include<bits/stdc++.h>
#define LL long long
#define For(i,a,b)	for(int i=a;i<=b;i++)
#define Rep(i,a,b)	for(int i=a;i>=b;i--)
#define pii pair<LL,int> 
using namespace std;
const int M=5e5+5;
const int N=5e5+5;
const LL inf=1e18;
int c,n,m,d,q;
LL w[M],dis[N],ans;
vector<pii> G[N];
void dij(int s){
	For(i,1,m+n)	dis[i]=inf;
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		LL W=pq.top().first;int u=pq.top().second;pq.pop();
		if(W!=dis[u])	continue;
		for(auto i:G[u]){
			int v=i.second;LL ww=i.first;
			if(W+ww<dis[v]){
				dis[v]=ww+W;
				pq.push(make_pair(dis[v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	LL res[n+5][m+5];
	For(i,1,m){
		cin>>w[i];
	}
	For(i,1,n){
		int k;cin>>k;
		For(j,1,k){
			int a;LL t;
			cin>>a>>t;
			G[i+m].push_back(make_pair(t,a));
			G[a].push_back(make_pair(t,i+m));
		}
	}
	For(i,1,n){
		dij(m+i);
		For(j,1,m){
			res[i][j]=dis[j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=inf;
		For(i,1,n){
			ans=min(ans,res[i][x]+res[i][y]);
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}