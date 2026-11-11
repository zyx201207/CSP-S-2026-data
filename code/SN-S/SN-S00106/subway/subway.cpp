#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
struct node{
	int p,c;
	bool operator <(const node &s) const{
		return s.c<c;
	}
};
int w[N],vis[N],n,m,c,d,T,q,dis[N];
vector<node> v[N];
void dij(int s){
	priority_queue<node> q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		int x = q.top().p;q.pop();
		if(!vis[x]){
			vis[x]=1;
			for(auto i:v[x]){
				int f=i.p,g=i.c;
				if(c>=12 && c<=19) g=2*T;
				dis[f]=min(dis[f],dis[x]+g);
				q.push({f,dis[f]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		int k,l=0,lst=0;cin >> k;
		for(int j=1;j<=k;j++){
			int a,b;cin >> a >> b;
			int sum=lst+b;
			if(j>1){
				v[l].push_back({a,sum});
				v[a].push_back({l,sum});
			}
			l=a,lst=b,T=b;
		}
	}
	
	while(q--){
		int s,t;cin >> s >> t;
		dij(s);
		cout << dis[t]+w[s]+w[t] << '\n';
	}
	return 0;
}
