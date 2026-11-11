#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1,N2=1e5+5;
long long w[N];
struct NODE{
	int a;
	long long t;
}c[502][N];
struct Ed{
	int wh,num;
	long long w;
};
vector<Ed> e[502][N],mo[N];
int dist[502][N],ci,m,n,d,q,st,en;
bool f[502][N];
void dj(int wh,int num){
	memset(dist,0x3f,sizeof(dist));
	dist[wh][num]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int minn=0x3f3f3f3f,poswh,posnum;
			for(int k=1;k<=n;++k){
				for(int l=1;l<=m;++l){
					if(minn>dist[k][l]){
						minn=dist[k][l];
						poswh=k;posnum=l;
					}
				}
			}
			f[poswh][posnum]=1;
			for(Ed& x:e[poswh][posnum]){
				if(!f[x.wh][x.num]&&dist[x.wh][x.num]>dist[poswh][posnum]+x.w)
					dist[x.wh][x.num]=dist[poswh][posnum]+x.w;
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ci>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>c[i][j].a>>c[i][j].t;
			e[i][j-1].push_back({i,j,0});
			e[i][j].push_back({i,j-1,0});
			mo[c[i][j].a].push_back({i,j,0});
		}
	}
	for(int i=1;i<=m;++i){
		int size=mo[i].size();
		for(int j=1;j<size;++j){
			for(int k=j+1;k<size;++k){
				e[mo[i][j].wh][mo[i][j].num].push_back({mo[i][k].wh,mo[i][k].num,w[j]+c[mo[i][k].wh][mo[i][k].num].t});
				e[mo[i][k].wh][mo[i][k].num].push_back({mo[i][j].wh,mo[i][j].num,w[k]+c[mo[i][j].wh][mo[i][j].num].t});
			}
		}
	}
	
	for(int i=1;i<=q;++i){
		int enmin=0x3f3f3f3f,wh,num;
		long long ans=0x3f3f3f3f3f3f3f3f;
		cin>>st>>en;
		for(Ed& x:mo[st]){
			dj(x.wh,x.num);
			for(Ed& y:mo[en]){
				if(enmin>dist[y.wh][y.num]){
					enmin=dist[y.wh][y.num];
					wh=y.wh;num=y.num;
				}
			}
			ans=min(ans,w[st]+c[x.wh][x.num].t+enmin+c[wh][num].t+w[en]);
		}
		cout<<ans<<' ';
	}
	
	return 0;
}
