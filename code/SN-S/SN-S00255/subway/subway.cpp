//SN-S00255
#include<bits/stdc++.h>
#define pii make_pair
using namespace std;
const int fyc=1e6+5;
const int imc=505;
int c,m,n,d,q,x,y,a,b;
long long w[fyc],k[imc],dis[imc][imc],ans;
map<pair<int,int>,long long> mp;
vector<int> g[fyc];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>b;
			mp[pii(i,a)]=b,g[a].push_back(i);
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int p=g[i].size();
		if(p==1) continue;
		for(int j=0;j<p;j++)
			for(int k=j+1;k<p;k++){
				int f1=g[i][j],f2=g[i][k];
				dis[f1][f2]=min(dis[f1][f2],mp[pii(f1,i)]+mp[pii(f2,i)]),dis[f2][f1]=dis[f1][f2];
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		cin>>x>>y;
		ans=LONG_LONG_MAX;
		for(int i=0;i<g[x].size();i++)
			for(int j=0;j<g[y].size();j++){
				int f1=g[x][i],f2=g[y][j];
				ans=min(ans,dis[f1][f2]+mp[pii(f1,x)]+mp[pii(f2,y)]);
			}
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
//latest 17:34:00
