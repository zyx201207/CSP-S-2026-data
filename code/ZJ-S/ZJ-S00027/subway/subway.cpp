#include<bits/stdc++.h>
#define int long long
#define INF 1145141919810
using namespace std;
int c,n,m,dn,q;
int w[520001],wp[520001];//wp条数 
int sl[520001][22],tl[520001][22];
//第i个站第j条经过的线以及耗时 
int d[601][601];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dn>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			int ap,tp;
			cin>>ap>>tp;
			wp[ap]++;
			sl[ap][wp[ap]]=i;
			tl[ap][wp[ap]]=tp;
		}
	}
//	cout<<"A";
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		d[i][j]=INF;
	for(int i=1;i<=n;i++)
		d[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=wp[i];j++)
		for(int k=j+1;k<=wp[i];k++)
			d[sl[i][j]][sl[i][k]]=d[sl[i][k]][sl[i][j]]=min(d[sl[i][j]][sl[i][k]],tl[i][j]+tl[i][k]);
	}
//	cout<<"B";
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--){
		int stt,enp,mx=INF;
		cin>>stt>>enp;
		for(int i=1;i<=wp[stt];i++)
		for(int j=1;j<=wp[enp];j++)
			mx=min(mx,d[sl[stt][i]][sl[enp][j]]+tl[stt][i]+tl[enp][j]);
		cout<<mx+w[stt]+w[enp]<<"\n";
	}
	return 0;
}
