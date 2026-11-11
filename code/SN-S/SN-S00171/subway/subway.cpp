#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
struct sta{
	int to;
	ll w;
};
vector<sta> way[505];
vector<int> saw[500005];
ll bg[505][505];
ll bd[505][505];
ll w[505];
void init(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			bg[i][j]=bd[i][j]=INT_MAX+INT_MAX+INT_MAX;
		}
		bg[i][i]=bd[i][i]=0;
	}
}
void floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(bd[i][k]+bd[k][j]<bd[i][j]&&i!=j){
					bd[i][j]=bd[i][k]+bd[k][j];
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	if(c<=6){
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int a;
				ll t;
				cin>>a>>t;
				way[a].push_back({i,t});
			}
		}
		init();
		for(int i=1;i<=m;i++){
			bd[i][i]=bg[i][i]=0;
			for(int j=i+1;j<=m;j++){
				ll vis[205];
				for(int k=0;k<=200;k++)vis[k]=0;
				for(sta k:way[i]){
					vis[k.to]=k.w;
				}
				for(sta k:way[j]){
					if(vis[k.to]!=0){
						bg[i][j]=bg[j][i]=min(bg[i][j],vis[k.to]+k.w);
					}
				}
				bd[i][j]=bd[j][i]=bg[i][j];
			}
		}
		floyd();
		while(q--){
			int x,y;
			cin>>x>>y;
			ll ans=0;
			ans=w[x]+w[y]+bd[x][y];
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(c>=7&&c<=11){
		init();
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			if(k==2){
				int a,b;
				ll wa,wb;
				cin>>a>>wa>>b>>wb;
				bg[a][b]=bg[b][a]=min(bg[a][b],wa+wb);
				bd[a][b]=bd[b][a]=bg[a][b];
			}else{
				int a;ll wa;
				cin>>a>>wa; 
			} 
		}
		floyd();
		for(int i=1;i<=q;i++){
			int a,b;
			cin>>a>>b;
			ll ans=w[a]+w[b]+bd[a][b];
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(c>=12&&c<=19){
		ll tim=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				bg[i][j]=bd[i][j]=INT_MAX+INT_MAX+INT_MAX;
			}
			bg[i][i]=bd[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int a;
				ll k;
				cin>>a>>k;
				tim=k;
				saw[a].push_back(i);
			}
		}
		for(int i=1;i<=m;i++){
			for(int k=0;k<saw[i].size();k++){
				for(int u=k+1;u<saw[i].size();u++){
					int l=saw[i][k],r=saw[i][u];
					bg[l][r]=bg[r][l]=min(bg[l][r],tim*2);
					bd[l][r]=bd[r][l]=bg[l][r];
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(bd[i][k]+bd[k][j]<bd[i][j]&&i!=j){
						bd[i][j]=bd[i][k]+bd[k][j];
					}
				}
			}
		} 
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			ll ans=LONG_LONG_MAX;
			for(int i:saw[x]){
				for(int j:saw[y]){
					ans=min(bd[i][j],ans);
				}
			}
			ans+=tim*4;
			ans+=w[x]+w[y];
			cout<<ans<<'\n';
		}
	}
	
	return 0;
}
