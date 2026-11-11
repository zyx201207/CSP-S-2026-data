#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
using namespace std;
mt19937_64 rd(time(0));
const int N=5e5+5,inf=1e18;
int n,m,d,q,f[505][505],c,a[N];
vector<pair<int,int>>e[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}	memset(f,0x3f,sizeof(f));
	for(int i=1,l;i<=n;i++){
		cin>>l;
		for(int j=1,x,t;j<=l;j++){
			cin>>x>>t;
			e[x].pb(mp(i,t));
		}f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<e[i].size();j++)
			for(int p=0;p<e[i].size();p++){
				if(j==p)continue;
				int x=e[i][j].ft,y=e[i][p].ft; 
				f[x][y]=min(f[x][y],e[i][j].sd+e[i][p].sd);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int p=1;p<=n;p++)
				f[j][p]=min(f[j][p],f[j][i]+f[i][p]);
	while(q--){
		int x,y,ans,bo=0;
		cin>>x>>y;
		for(int i=0;i<e[x].size();i++){
			for(int j=0;j<e[y].size();j++){
				int x1=e[x][i].ft,y1=e[y][j].ft;
				if(!bo)bo=1,ans=e[x][i].sd+e[y][j].sd+f[x1][y1];
				if(f[x1][y1]<ans)ans=min(ans,e[x][i].sd+e[y][j].sd+f[x1][y1]);
			}
		}
		ans+=a[x]+a[y];
		cout<<ans<<endl;
	}
	return 0;
}

