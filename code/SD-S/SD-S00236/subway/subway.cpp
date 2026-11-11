#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
const int N=500+10;
const int M=5e5+10;
const ll inf=1e18;
int n,m,d;
int w[M];
int du[M];
PII to[M][21];
ll len[N][N];
vector<PII> p[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	//-------------------------------
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			p[i].push_back({a,t});
			to[a][++du[a]]={i,t};
		}
	}
	//-------------------------------‘§¥¶¿Ì 
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) len[i][j]=inf;
		len[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<p[i].size();j++){//5e5
			int a=p[i][j].first;
			ll t1=p[i][j].second;
			for(int k=1;k<=du[a];k++){//1e7
				int b=to[a][k].first;
				ll t2=to[a][k].second;
				len[i][b]=min(len[i][b],t1+t2);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)//1.25e8
				len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
	//-------------------------------
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf,sum=w[x]+w[y];
		for(int i=1;i<=du[x];i++){
			int a=to[x][i].first,w1=to[x][i].second;
			for(int j=1;j<=du[y];j++){
				int b=to[y][j].first,w2=to[y][j].second;
				ans=min(ans,sum+len[a][b]+w1+w2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
