#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,NN=502;
int c,n,m,d,i,j,x,xr,yr,y,T,k;
int qzh[N],kk[N],f[N][21],dd[N],w[N],p[N],q[N],bq[NN][NN];

struct Node{
	int x,y;
}qre;
vector<Node>a[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=m;i++)
	  for(j=1;j<=m;j++)
	    if(i!=j)bq[i][j]=1e16;
	for(i=1;i<=n;i++){
		cin>>kk[i];
		for(j=1;j<=kk[i];j++){
			cin>>x>>y;
			p[j]=x;q[j]=y;
			for(k=1;k<j;k++)bq[p[k]][x]=bq[x][p[k]]=min(bq[p[k]][x],y+q[k]);
			f[x][++dd[x]]=i;
		}
	}
	for(k=1;k<=m;k++)
	  for(i=1;i<=m;i++)
	    if(i!=k)
	      for(j=1;j<=m;j++)
	        if(j!=i&&j!=k){
	          bq[i][j]=min(bq[i][j],bq[i][k]+bq[k][j]);
			}
	while(T--){
		cin>>xr>>yr;
		cout<<bq[xr][yr]+w[xr]+w[yr]<<"\n";
	}
	return 0;
}