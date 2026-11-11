#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005;
int c,n,m,d,q;
ll f[N][N];
int w[N];
int a[N],t[N];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof f);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%d",&w[i]);
	for(int i=1;i<=n;++i) {
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;++j) {
			scanf("%d%d",&a[j],&t[j]);
			//cout<<a[i]<<" "<<t[i]<<endl;
		}
		//cout<<endl;
		for(int j=1;j<=k;++j) {
			for(int to=1;to<=k;++to) {
				if(to==j) continue;
				//cout<<a[j]<<" "<<a[to]<<endl;
				f[a[j]][a[to]]=f[a[to]][a[j]]=t[j]+t[to];
				//cout<<t[a[j]]+t[a[to]]<<endl;
			}
		}
	}
	/*cout<<endl<<endl<<endl;
		for(int i=1;i<=m;++i) {
			for(int j=1;j<=m;++j) {
				cout<<f[i][j]<<" ";
			}
			cout<<endl;
		}
	cout<<endl<<endl<<endl;*/
	for(int k=1;k<=m;++k) {
		for(int i=1;i<=m;++i) {
			for(int j=1;j<=m;++j) {
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
/*cout<<endl<<endl<<endl;
		for(int i=1;i<=m;++i) {
			for(int j=1;j<=m;++j) {
				cout<<f[i][j]<<" ";
			}
			cout<<endl;
		}
	cout<<endl<<endl<<endl;*/
	for(int i=1;i<=q;++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%lld\n",f[u][v]+w[u]+w[v]);
	}
	return 0;
}
/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2





0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
