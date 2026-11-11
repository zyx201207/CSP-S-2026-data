/*
走了那么久，难道又回头吗 ——《依·抱》
All for myself, not anyone else.
*/
/*
坐车时间不限，n很小，考虑预处理每对线路之间换乘的花费
类似floyd？
然后近+出单独算，询问是O(d^2)的，完美解决q<=1e5
floyd的复杂度是O(n^3)
存一下每两个点之间有没有交集，有交集的话交集内最小换乘代价是多少
读入时每读入一个算一下这条线进去后能和哪些点产生交集，把min取一下
总复杂度？
O(n*k*d+n^3+d^2*q)=5e9+eps
评测机最快3.7e9
这有点大啊
nkd的瓶颈可以优化吗
先写着 
nkd可以优化成md^2
O(md^2+n^3+d^2*q)=3e8+eps
这时间复杂度okay的 
神机保佑 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define TERRY_MC
#define endl '\n'
const int N=5e2+10,M=5e5+10; 
int c,d,m,n,q,w[M];
unordered_map<int,int> co[M];//从i地铁站站厅到站台路线j的花费为k
ll dis[N][N];
//不要卡我umap我求你了 
//不敢写自定义hash我怕错啊啊啊 
int main() {
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#ifndef TERRY_MC
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	int k,a,t;
	for(int i=1;i<=n;i++) {
		cin>>k; 
		for(int j=1;j<=k;j++) {
			cin>>a>>t;
			co[a][i]=t;
		}
	}
	for(int i=1;i<=m;i++) {
		for(pair<int,int> p1:co[i]) {
			for(pair<int,int> p2:co[i]) {
				if(p1.first==p2.first)
					continue;
				dis[p1.first][p2.first]=dis[p2.first][p1.first]=min(dis[p1.first][p2.first],1LL*p1.second+p2.second);
			}
		}
	}
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
	int x, y;
	while(q--) {
		cin>>x>>y;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(pair<int,int> _x:co[x]) {
			for(pair<int,int> _y:co[y]) {
				ans=min(ans,dis[_x.first][_y.first]+_x.second+_y.second);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}

	return 0;
}
//fin.

