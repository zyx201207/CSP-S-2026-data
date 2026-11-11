#include<bits/stdc++.h>
#define pb push_back 
using namespace std;
typedef long long ll;
ll c,n,m,d,q,cnt,dis[2000000],vis[2000000],pian[1100][1100];
struct S{
	ll d,t;
};
vector<S>ve[2000000];
struct S2{
	ll d,t;
	bool operator <(const S2 &y)const{
		return t>y.t;
	}
};
void dijkstra(int x){
	priority_queue<S2>q;
	memset(dis,0x7f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[x]=0;
	vis[x]=1;
	q.push({x,0});
	while(!q.empty()){
		S2 t=q.top();q.pop();
		int td=t.d;
		vis[td]=1;
		for(auto i:ve[td]){
			int nd=i.d,nt=i.t;
			if(dis[nd]>dis[td]+nt&&!vis[nd]){
				dis[nd]=dis[td]+nt;
				q.push({nd,dis[nd]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	cnt=2*m;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		ve[i].pb({i+m,x});
		ve[i+m].pb({i,x});
	}
	for(int i=1;i<=n;i++){
		int k,x,t,pre=-1;
		cin>>k;
		while(k--){
			cin>>x>>t;
			ve[++cnt].pb({x+m,t});
			ve[x+m].pb({cnt,t});
			if(pre!=-1){
				ve[cnt-1].pb({cnt,0});
				ve[cnt].pb({cnt-1,0});
			}
			else pre=0;
		}
	}
	if(m<q){
		for(int i=1;i<=m;i++){
			dijkstra(i);
			for(int j=i+1;j<=m;j++){
				pian[i][j]=dis[j];
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			if(x>y)swap(x,y);
			cout<<pian[x][y]<<"\n";
		}
	}
	else{
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			dijkstra(x);
			cout<<dis[y]<<"\n";
		}
	}
	
	return 0;
}