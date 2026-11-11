#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[50005],k[50005],a[10005][10005],t[10005][10005],ot[10005][10005];
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int v=1;v<=m;v++){
		cin>>w[v];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			ot[i][a[i][j]]=t[i][i]+t[i][j];
		}
	}
	int x,y;
	for(int r=1;r<=q;r++){
		cin>>x>>y;
		cout<<ot[x][y]+w[x]+w[y]<<endl;
		
	}
	return 0;
}

