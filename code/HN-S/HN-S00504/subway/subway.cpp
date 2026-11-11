#include<bits/stdc++.h>//好可爱的T2
#define int long long //我算是知道CSP-S怎么“队友搞心态”了，右边一个傻福hzy一上来就打牌。。 
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;//疾如风，徐如林 
int C,n,m,d,q,w[514514],ks[514],ed[514][514],f[514][514],c[514];//！？击击败，败败击！？ 
vector<pii> e[514514];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(ed,0x3f,sizeof(ed));
	cin >> C >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		ed[i][i]=0;
		cin >> ks[i];
		c[i]=i;
		for(int j=1;j<=ks[i];j++){
			int a,t;
			cin >> a >> t;
			e[a].push_back({c[i],t});
		}
	}
	for(int i=1;i<=m;i++){
		int n2=e[i].size();
		for(int j=0;j<n2;j++){
			for(int k=j+1;k<n2;k++){
				int X=e[i][j].fi,Y=e[i][k].fi,cot=e[i][j].se+e[i][k].se;
				ed[X][Y]=min(ed[X][Y],cot);
				ed[Y][X]=min(ed[Y][X],cot);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ed[i][j]=min(ed[i][j],ed[i][k]+ed[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout << i << ' ' << j << ' ' << ed[i][j] << '\n';
//		} 
//	}
//	cout << ed[1][2] << '\n';
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		int as=w[x]+w[y],ans=LLONG_MAX;
		for(auto j:e[x]){
			for(auto k:e[y]){
				ans=min(ans,j.se+k.se+as+ed[j.fi][k.fi]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
