#include <bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define foR(i,a,b) for(int i=a;i>=b;i--)

const int maxn=506,maxm=5e5+6,inf=1e15;
int c,n,m,d,q;
int w[maxm],k[maxn],dis[400][400];
struct C{
	int v,w;
	bool operator<(const C &c) const{
		return (w==c.w)?(v<c.v):(w<c.w);
	}
};
vector<int> a[maxn],t[maxn];
vector<C> ljb[maxn+maxm];

void dij(int i){
	//cout<<"dij "<<i<<'\n';
	priority_queue<C>q;
	q.push({i,0});
	For(j,1,n+m)dis[i][j]=inf;
	dis[i][i]=0;
	while(q.size()){
		int nn=q.top().v,mm=q.top().w;
		//cout<<"at "<<nn<<' '<<mm<<'\n';
		q.pop();
		if(mm>dis[i][nn])continue;
		for(auto uu:ljb[nn]){
			//cout<<"se "<<uu.v<<' '<<uu.w<<'\n';
			if(dis[i][uu.v]>dis[i][nn]+uu.w){
				dis[i][uu.v]=dis[i][nn]+uu.w;
				q.push({uu.v,dis[i][uu.v]});
				//cout<<"sw "<<uu.v<<' '<<dis[i][uu.v]<<'\n';
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	For(i,1,m)cin>>w[i];
	For(i,1,n){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		For(j,1,k[i]){
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt); 
			ljb[m+i].push_back({aa,tt});
			ljb[aa].push_back({m+i,tt});
		}
		For(i,1,m)dij(i);
	}
	For(i,1,q){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
	}
	return 0;
}

