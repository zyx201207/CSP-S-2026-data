#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001];
int a[3][500001],t[3][500001],k[501];
bool ishavea[500001],ishaveb[500001];
struct jihua{
	int x,y;
};
jihua p[100001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>p[i].x>>p[i].y;
	}
	for(int i=1;i<=q;i++){
		cout<<w[p[i].x]+w[p[i].y]+t[1][p[i].x]+t[1][p[i].y]<<endl;
	}
	return 0;
}
