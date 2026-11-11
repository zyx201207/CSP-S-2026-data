/*
本题的巧妙之处就在于边权的转化
原本的方式肯定是不行的
因为它至少是全源最短路
所以我们把边权转化为线路之间的边权
这样就可以Floyd求最短路
时间就不会爆炸了。

然后这个 d 也是有巧思的
因为 d<=20，所以我们对于每一个询问的 x,y
都枚举他们所能到的线路的最短路即可。
这里是 O(Qd^2) 的

我真聪明qwq
时间复杂度 O(n^3)
*/
#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int c,n,m,d,q;//出题人DQ吃多了胖了（
long long mat[510][510];
int tt[N];
vector<int> lu[N];
map<int,int> tim[510];

int main(){
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(mat,0x3f,sizeof mat);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>tt[i];
	for(int i=1;i<=n;i++){
		mat[i][i]=0;
		int t;cin>>t;
		while(t--){
			long long a,t;cin>>a>>t;
			tim[i][a]=t;
			for(int j=0;j<lu[a].size();j++){
				int tmp=lu[a][j];
				mat[i][tmp]=mat[tmp][i]=min(mat[i][tmp],tim[tmp][a]+t);
			}
			lu[a].push_back(i);
		}
	}
	for(int k=1;k<=n;k++)//Floyd 依旧 k 必须放外面
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		long long ans=LLONG_MAX;
		for(int i=0;i<lu[x].size();i++){
			for(int j=0;j<lu[y].size();j++){
				int a=lu[x][i],b=lu[y][j];
				ans=min(ans,mat[a][b]+tt[x]+tt[y]+tim[a][x]+tim[b][y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
