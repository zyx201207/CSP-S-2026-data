#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
using namespace std;
const int N=510;
const int M=5e5+10;
int c,n,m,d,q;
int w[M],k[M],t[N][M];
int gm[N][N];
set<int> st[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(gm,0x3f,sizeof(gm));
	memset(t,0x3f,sizeof(t));
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a;
			cin>>a>>t[i][j];
			st[i].insert(a);
			for(int c=1;c<=n;c++){
				if(st[c].count(a)){
					gm[c][i]=min(gm[c][i],t[c][a]);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<'\n';
			return 0;
		}
		ans+=w[x]+w[y]+t[x][x];
		for(int i=1;i<=n;i++){
			if(st[i].count(x)) x=i
			if(st[i].count(x)) y=i;
		}
		
		
	}
	return 0;
}
/*
__builtin_clz
priority_queue
*/