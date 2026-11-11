#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,w[10001];
int flyd[1001][1001];
struct node{
	int v,w;
}a[1000001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			flyd[i][j]=1e9;
		}
	}
	int j;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>a[j].v>>a[j].w;		
		}
		for(int l=1;l<=k;l++){
			for(int h=l;h<=k;h++){
				if(a[l].v!=a[h].v){
					flyd[a[l].v][a[h].v]=a[l].w+a[h].w;
					flyd[a[h].v][a[l].v]=a[l].w+a[h].w;
				}
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(j=1;j<=m;j++){
				flyd[i][j]=min(flyd[i][k]+flyd[k][j],flyd[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<flyd[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}


