#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,q,D,dis[514][514],d[500010],k[514];//line i to line j
vector<pair<int,int> >t[500010];
void floyd(){
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		for(int k=1;k<=n;k++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>d[i];
	memset(dis,31,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			t[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=m;i++){
		int siz=t[i].size();
//		for(int j=0;j<siz;j++)cout<<t[i][j].first<<" ";
//		cout<<endl;
		for(int j=0;j<siz-1;j++)for(int k=1;k<siz;k++){
			int x=t[i][j].first,y=t[i][k].first,d1=t[i][j].second,d2=t[i][k].second;
			dis[x][y]=dis[y][x]=min(dis[x][y],d1+d2);
		}
	}
	floyd();
//	for(int i=1;i<=n;i++,cout<<endl){
//		for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";
//	}
	while(q--){
		int x,y,ans=1ll<<60;
		cin>>x>>y;
		for(auto u:t[x])for(auto v:t[y]){
			ans=min(ans,d[x]+d[y]+u.second+v.second+dis[u.first][v.first]);
		}
		cout<<ans<<endl;
	}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
}
/*zha lie O(n^3+m*d^2+q*d^2)
rt. ke neng bei ka yi liang ge dian.
//freopen();

Rrhar'il AT 17.6
--- ---
---   ---
---   ---
--- ---
---   ---
---     ---

xxx xx xx xxxxxxx
*/
