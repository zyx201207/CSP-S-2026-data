#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
const int maxm=510;
struct node{
	int to,w;
};
int c,n,m,d,q; //分别表示测试点编号、地铁站数、地铁线路数、每个地铁站最多被几条线路经过，以及出行计划数
int w[maxn],k[maxm],mmap[maxm][maxm],cnt[maxn];
node p[maxn][30];
//vector<node> t[maxm];
//vector<node> p[maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >>c >>m >>n >>d >>q;
	for(int i=1;i<=n;i++){
		cin >>w[i];
	}
	for(int i=1;i<=m;i++){
		cin >>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin >>x >>y;
//			t[i].push_back({x,y});
			p[x][++cnt[x]]={i,y};
		}
	}
	memset(mmap,0x3f,sizeof(mmap));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				int t1=p[i][j].to,t2=p[i][k].to;
				mmap[t1][t2]=mmap[t2][t1]=min(mmap[t1][t2],p[i][j].w+p[i][k].w);
			}
		}
	}
	for(int i=1;i<=m;i++){
		mmap[i][i]=0;
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				mmap[i][j]=min(mmap[i][j],mmap[i][k]+mmap[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin >>x >>y;
		int ans=LONG_LONG_MAX;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				int t1=p[x][i].to,t2=p[y][j].to; //起点在t1条线路，终点在t2条线路 
				ans=min(ans,mmap[t1][t2]+p[x][i].w+p[y][j].w);
			}
		}
		cout <<ans+w[x]+w[y] <<'\n';
	}
	return 0;
}
//15：55 过大样例？？？？
//O(d^2*(m+q)+n^3) (3.65e8) 
//祈求测评机神力！！！ 