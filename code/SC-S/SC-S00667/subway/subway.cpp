#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[600][500010],t[600][500010],w[600],k[600];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=n;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j = 1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			t[a[i][j]][i] = t[i][a[i][j]];
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int l = 1;l<=n;l++){
				if(t[i][j]!=0&&t[i][l]!=0&&t[j][l]!=0){
					int ax = t[i][j] ,bx = t[i][l] ,cx = t[j][l];
					t[i][j] = min(ax,bx+cx);
					t[j][i] = t[i][j];
				}
			}
		}
	}
	for(int i = 1;i<q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+t[x][y]<<'\n';
	}
	return 0;
}