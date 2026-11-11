#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,d,q;
const int N=510,M=5e5+10; 
int w[M],k;
vector<pair<int,int>> t[M]; 
int dis[N][N];


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			t[x].push_back({i,y});
		}
	}
	// 预处理每站中站台换乘时间，取最小值放入dis
	for(int k=1;k<=m;k++)
		for(auto i:t[k])
			for(auto j:t[k])
				if(i.first!=j.first)
					dis[i.first][j.first]=dis[j.first][i.first]=
						min(dis[i.first][j.first],i.second+j.second);
	// Floyd
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	// O(d^2) 输出 
	while(q--){
		int st,ed;
		cin>>st>>ed;
		int ans=LLONG_MAX;
		for(auto i:t[st])
			for(auto j:t[ed])
				ans=min(ans,i.second+j.second+dis[i.first][j.first]);
		cout<<ans+w[st]+w[ed]<<"\n";
	}
	return 0;
}
