#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back

const int mod=998244353;

const int N=510,M=500010;

int w[M],d[N][N],x,y;

vector<pii> f[M];

int c,n,m,D,q,k,a,t;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x1f,sizeof d);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	d[i][i]=0;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			pii o={i,t};
			f[a].pb(o);
		}
	}
//	for(auto o:f[2]){
//		cout<<o.fi<<" ?"<<o.se<<endl;
//	}
	for(int i=1;i<=m;i++){
		int len=f[i].size();
		if(len>=2){
			for(int u=0;u<len;u++)
			for(int v=0;v<u;v++){
				pii l=f[i][u],r=f[i][v];
				int op=l.se+r.se,u1=l.fi,v1=r.fi;
				d[u1][v1]=d[v1][u1]=min(d[u1][v1],op);
			}
		}
	} 
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(d[i][j]>d[i][k]+d[k][j])
			d[i][j]=d[i][k]+d[k][j];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//		cout<<d[i][j]<<" ";
//		cout<<endl; 
//	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int num=w[x]+w[y];//wyq ¹¾¹¾
		int ans=1e18;
		for(pii j:f[x])
		for(pii k:f[y]){
			int u=j.fi,v=k.fi;
//			cout<<":::"<<u<<" "<<v<<" "<<j.se<<" "<<k.se<<endl;
			ans=min(ans,d[u][v]+j.se+k.se);
		}
//		cout<<ans<<" "<<num<<" ";
		cout<<ans+num<<"\n";
	}
	return 0;
}
