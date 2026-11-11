#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;
int c,n,m,d,q,k;
int w[500005],f[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cout<<"010\n";
	cin>>c>>n>>m>>d>>q;
	vector<vector<pair<int,int>>>line_num(m+2);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)f[i][j]=0;
			else f[i][j]=INF;
		}
	}
	//cout<<"011\n";
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		//cout<<"\ni:"<<i<<" k:"<<k<<"\n";
		int a,t;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			line_num[a].push_back({i,t});
			//cout<<"a:"<<a<<"{"<<i<<","<<t<<"}\n";
		}
	}
	//cout<<"012\n";
	for(int i=1;i<=m;i++){
		if(line_num[i].size()>1){
			for(pair<int,int>pa1:line_num[i]){
				for(pair<int,int>pa2:line_num[i]){
						if(pa1==pa2)continue;
						f[pa1.first][pa2.first]=min(f[pa1.first][pa2.first],pa1.second+pa2.second);
				}
			}
		}
	}
	//cout<<"013\n";
	for(int o=1;o<=n;o++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||j==o||i==o)continue;
				f[i][j]=min(f[i][o]+f[o][j],f[i][j]);
			}
		}
	}
	//cout<<"014\n";
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int ans=INF;
		for(pair<int,int>pa1:line_num[x]){
			for(pair<int,int>pa2:line_num[y]){
				ans=min(ans,pa1.second+pa2.second+f[pa1.first][pa2.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	//cout<<"015\n";
	return 0;
}
