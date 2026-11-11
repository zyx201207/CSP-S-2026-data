#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int c,n,m,d,qs;
vector<pair<int,int> >sub[100001];
int w[1000001];
long long dis[1001][1001];
vector<int>z[1000001];
map<pair<int,int>,long long>hx;
bool v[1000001];
bool vs[5001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qs;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
			sub[i].push_back({a,b});
			z[a].push_back(i);
			hx[{a,i}]=b;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		if(z[i].size()>=2){
			for(auto sw1:z[i]){
				for(auto sw2:z[i]){
					if(sw1!=sw2){
						dis[sw1][sw2]=min(dis[sw1][sw2],hx[{i,sw1}]+hx[{i,sw2}]);
					}
				}
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
	for(int i=1;i<=qs;i++){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(auto sx:z[x]){
			for(auto sy:z[y]){
				ans=min(ans,w[x]+w[y]+hx[{x,sx}]+hx[{y,sy}]+dis[sx][sy]);
			}
		}
		cout<<ans<<"\n";
	}
}
