#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500005],k[1005],dis[1005][1005];
vector<int> v[500005],vv[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];j++) cin>>x>>y,v[x].push_back(i),vv[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		int len=v[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				ll xx=v[i][j],ti1=vv[i][j],yy=v[i][k],ti2=vv[i][k];
				dis[xx][yy]=min(dis[xx][yy],ti1+ti2);
				dis[yy][xx]=min(dis[yy][xx],ti1+ti2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ll ans=0x3f3f3f3f3f3f3f3f;
		int x,y;
		cin>>x>>y;
		int len1=v[x].size(),len2=v[y].size();
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				ans=min(ans,dis[v[x][i]][v[y][j]]+vv[x][i]+vv[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}