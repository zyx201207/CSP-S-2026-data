#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[514514];
int dis[555][555];
unordered_map<int,int>mp[514514];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int id,x;cin>>id>>x;
			mp[id][i]=x;
		}
	}
	//Floyd?!
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto it=mp[i].begin();it!=mp[i].end();it++){
			for(auto it2=mp[i].begin();it2!=mp[i].end();it2++){
				if(it==it2)continue;
				dis[it->first][it2->first]=min(dis[it->first][it2->first],it->second+it2->second);
				dis[it2->first][it->first]=min(dis[it2->first][it->first],it->second+it2->second);
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
		int x,y;cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3fll;
		for(auto it=mp[x].begin();it!=mp[x].end();it++){
			for(auto it2=mp[y].begin();it2!=mp[y].end();it2++){
				int dist=dis[it->first][it2->first]+w[x]+w[y]+it->second+it2->second;
				ans=min(ans,dist);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}