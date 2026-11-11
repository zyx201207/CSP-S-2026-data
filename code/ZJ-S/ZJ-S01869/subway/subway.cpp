#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
const int M=5e5+5,N=505;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,k[N];
ll w[M],f[N][N];
vector<pii>a[N],b[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back({0,0});
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back({x,y});
			b[x].push_back({i,y});
		}
		sort(a[i].begin(),a[i].end());
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int i1=1,i2=0;i1<=k[i];i1++){
				while(a[j][i2].first<a[i][i1].first&&i2<k[j])i2++;
				if(a[j][i2].first==a[i][i1].first){
					
					f[i][j]=min(f[i][j],a[j][i2].second+a[i][i1].second);
					f[j][i]=f[i][j];
				}
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		ll ans=inf;
		cin>>x>>y;
		for(pii i:b[x])
			for(pii j:b[y])
				ans=min(ans,f[i.first][j.first]+i.second+j.second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
T2 怎么也秒了 
把站厅与站厅之间的最短路预处理出来(Floyd O(n^3)) 
然后枚举起点站和终点站走哪两个站厅(O(q d^2))
15:32 写完还没测 
15:45 AC
*/ 
