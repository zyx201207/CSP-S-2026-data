#include <bits/stdc++.h>
using namespace std;
const int MAXM=5e5+5;
const int MAXD=25;
const int MAXN=505;
const int MAXK=15; 
const int MAXQ=1e5=5; 
int w[MAXM],k[MAXM],a[MAXN][MAXK],t[MAXN][MAXK];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int y=1;y<=q;y++){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]<<"\n";
		}
	}
	return 0;
}