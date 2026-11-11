#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<long long,int>
#define pb push_back
#define Ag first
#define Zn second
using namespace std;
const int N=5e5+10;
const bool ckr=0;

int n,a,c,m,k,d,q,hello,x,y;
ll dis[509][509],w[N],t;
vector<pli> info[N];
void solve(){
	n=hello=0;
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	c++;c--;c*=c;c=sqrt(c);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			info[a].pb({t,i});
		}
	}
	for(int i=1;i<=n;i++){
			dis[i][i]=0;
	}	
	for(int i=1;i<=m;i++){
		for(int j=0;j<info[i].size();j++){
			for(int l=j+1;l<info[i].size();l++){
				dis[info[i][j].Zn][info[i][l].Zn]=dis[info[i][l].Zn][info[i][j].Zn]=min(dis[info[i][l].Zn][info[i][j].Zn],info[i][l].Ag+info[i][j].Ag);
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
		cin>>x>>y;
		ll res=0xfffffffffffffff;
		for(int i=0;i<info[x].size();i++){
			for(int j=0;j<info[y].size();j++){
				res=min(res,info[x][i].Ag+dis[info[x][i].Zn][info[y][j].Zn]+info[y][j].Ag);
			}
		}
		cout<<res+w[x]+w[y]<<endl;
	}
	return ;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	solve();

	return 0;
}

