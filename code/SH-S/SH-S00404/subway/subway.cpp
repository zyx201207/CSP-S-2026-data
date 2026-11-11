#include<bits/stdc++.h>
#define FILE_NAME "subway"
using namespace std;
const int N=510,M=500010,Q=100010;
int c,n,m,d,q,w[M],x[Q],y[Q],dis[N][N];
vector<int>a[M],t[M];
int main(){
	freopen(FILE_NAME".in","r",stdin);
	freopen(FILE_NAME".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1,ki;i<=n;++i){
		cin>>ki;
		for(int j=0,ai,ti;j<ki;++j){
			cin>>ai>>ti;
			a[ai].push_back(i);
			t[ai].push_back(ti);
		}
	}
	for(int i=1;i<=q;++i){
		cin>>x[i]>>y[i];
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		for(int j=0;j<a[i].size();++j){
			for(int k=j+1;k<a[i].size();++k){
				int j0=a[i][j],k0=a[i][k];
				dis[j0][k0]=dis[k0][j0]=min(dis[j0][k0],t[i][j]+t[i][k]);
			}
		}
	}
	for(int i=n-2;i>=1;--i){
		for(int j=i+2;j<=n;++j){
			for(int k=i+1;k<j;++k){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;++i){
		int ans=0x3f3f3f3f;
		for(int j=0;j<a[x[i]].size();++j){
			for(int k=0;k<a[y[i]].size();++k){
				ans=min(ans,t[x[i]][j]+t[y[i]][k]+dis[a[x[i]][j]][a[y[i]][k]]);
			}
		}
		cout<<ans+w[x[i]]+w[y[i]]<<"\n";
	}
	return 0;
}
