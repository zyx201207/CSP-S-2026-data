#include<bits/stdc++.h>
using namespace std;
#define pii make_pair 
#define int long long
const int N=505,M=5e5+5;
int f[N][N],w[M];
map<pair<int,int>,int> t;
vector<int> v[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			t[pii(i,x)]=y;
			v[x].push_back(i);
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		if(v[i].size()!=1){
			int l=v[i].size();
			for(int qt=0;qt<l;qt++){
				for(int w=0;w<qt;w++){
					int lina=v[i][qt],linb=v[i][w];
					f[lina][linb]=t[pii(lina,i)]+t[pii(linb,i)];
					f[linb][lina]=f[lina][linb];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				f[j][i]=f[i][j];
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int mn=1e18;
		for(int lina:v[x]){
			for(int linb:v[y]){
				mn=min(mn,f[lina][linb]+w[x]+w[y]+t[pii(lina,x)]+t[pii(linb,y)]);
			}
		}
		cout<<mn<<'\n';
	}
	return 0;
} 