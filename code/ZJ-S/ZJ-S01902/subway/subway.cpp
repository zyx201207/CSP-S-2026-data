#include<bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define pf push_back
#define pof pop_back
#define ft first
#define sd second
#define endl '\n'
using namespace std;
long long c,n,m,d,q;
long long w[500010];
long long k[510];
vector<pair<long long,long long>> tai[510];
long long dis[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2){
			te=0;
		}
		for(int j=1;j<=k[i];j++){
			long long a,t;cin>>a>>t;
			tai[i].pb({a,t});
		}
	}
	if(m<=1000){
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			for(int j=0;j<k[i];j++){
				for(int kk=0;kk<k[i];kk++){
					if(j==kk){
						continue;
					}
					dis[tai[i][j].ft][tai[i][kk].ft]=min(dis[tai[i][j].ft][tai[i][kk].ft],tai[i][j].sd+tai[i][kk].sd);
					dis[tai[i][kk].ft][tai[i][j].ft]=min(dis[tai[i][kk].ft][tai[i][j].ft],tai[i][kk].sd+tai[i][j].sd);
				}
			}
		}
		for(int i=1;i<=m;i++){
			dis[i][i]=0;
		}
		for(int kk=1;kk<=m;kk++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			long long st,en;cin>>st>>en;
			cout<<dis[st][en]+w[st]+w[en]<<endl;
		}
	}
	return 0;
}
