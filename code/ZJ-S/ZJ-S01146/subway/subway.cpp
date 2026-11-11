#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+5;
ll c,n,m,d,q,w[M],dis[2000][2000];
vector<ll>b[M];
void c1to6(){
	for(int i=1;i<=n;i++){
		ll k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			dis[n+a][i]=t;
			dis[i][n+a]=t;
		}
	}
	for(int k=1;k<=n+n+m;k++){
		for(int i=1;i<=n+n+m;i++){
			for(int j=1;j<=n+n+m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		cout<<dis[x+n][y+n]+w[x]+w[y]<<endl;
	}
}
void c7to11(){
	for(int i=1;i<=n;i++){
		ll k,a1,t1,a2,t2;
		cin>>k;
		cin>>a1>>t1;
		if(k==2){
			cin>>a2>>t2;
			dis[a1][a2]=dis[a2][a1]=t1+t2;
	}
	}
	for(int k=1;k<=m;k++){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
}
void c12to19(){
	ll k,a,t;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			b[a].push_back(i);
			dis[i][i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<b[i].size();j++){
			for(int k=0;k<b[i].size();k++){
				if(j==k)continue;
				dis[b[i][k]][b[i][j]]=dis[b[i][j]][b[i][k]]=2*t;
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
	for(int i=1;i<=q;i++){
		ll x,y,ans=4e18;
		cin>>x>>y;
		for(int j=0;j<b[x].size();j++){
			for(int k=0;k<b[y].size();k++){
				ans=min(ans,dis[b[x][j]][b[y][k]]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x1111,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c<=6){
		c1to6();
	}else if(c<=11){
		c7to11();
	}else if(c<=19){
		c12to19();
	}else{
		c1to6();
	}
	return 0;
}