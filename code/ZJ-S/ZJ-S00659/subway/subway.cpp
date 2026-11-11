#include<bits/stdc++.h>
using namespace std;
struct dtz{
	int a,t;
};
dtz p[505][500005];
int w[500005];
int main(){
	freopen("subway.in", "r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>p[i][j].a>>p[i][j].t;
		}
	}
	return 0;
}
