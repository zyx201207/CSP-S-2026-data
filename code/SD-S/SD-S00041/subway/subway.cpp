#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
#define p(i,j) make_pair(i,j)
#define DEBUG_CODE 0
#define NDB if(!DEBUG_CODE)
#define DB if(DEBUG_CODE)
using namespace std;
const int N=4e6+10;
const ll mod=1e18+7;
ll n,m,x,y,z,sum,ans,cnt,tot,k,T,u,v,w,l,r,opt,a[N],c,d,dis[N],vis[N];
vector<pii > e[N];
priority_queue<pii ,vector<pii >,greater<pii > > q;
void add(int u,int v,int w){
	e[u].push_back(p(v,w));
	e[v].push_back(p(u,w));
}
//string o(int x){
//	if(x<=m) return "IN"+to_string(x);
//	x-=m;
//	if(x<=m) return "STATION"+to_string(x);
//	x-=m;
//	return "LINE"+to_string(x%d)+"_STATION"+to_string(x/d);
//}
int main(){
	NDB{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>x;
		add(i,i+m,x);
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			add(a+m,2*m+(a*d)+i,t);
			if(j>1){
				add(2*m+(a*d)+i,2*m+(cnt*d)+i,0);
//				DB if(i==3){
//					cout<<"!"<<j<<" "<<o(2*m+(a*d)+i)<<" "<<o(2*m+(cnt*d)+i)<<"!\n";
//					cout<<"?";
//					for(auto v:e[2*m+(a*d)+i]) cout<<o(v.first)<<"="<<v.first<<" ";
//					cout<<"?\n";
//				}
				
			}
			cnt=a;
		}
	}
//	DB for(int i=1;i<=2*m+m*d+d;i++){
//		for(auto j:e[i]){
//			if(i<j.first) cout<<o(i)<<" "<<o(j.first)<<" "<<j.second<<"\n";
//		}
//	}
	while(T--){
		cin>>x>>y;
		for(int i=1;i<=(2*m+m*d+d+10);i++) dis[i]=mod,vis[i]=0;
		dis[x]=0;
		while(!q.empty()) q.pop();
		q.push({0,x});
		while(!q.empty()){
			ll u=q.top().second;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto v:e[u]){
				if(dis[u]+v.second<dis[v.first]){
//					vis[v.first]=1;
					dis[v.first]=dis[u]+v.second;
					q.push(p(dis[v.first],v.first));
				}
			}
		}
//		cout<<T<<"\n";
//		DB for(int i=1;i<=2*m+m*d+d;i++) if(dis[i]!=mod) cout<<o(i)<<" "<<dis[i]<<"\n";
//		DB cout<<"\n"; 
		cout<<dis[y]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


地铁口: 1~m
站厅: m+1~2m
i号线j站站台： 2m+(j*d)+i
*/

