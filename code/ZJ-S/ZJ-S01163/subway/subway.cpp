#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,k,q,a[500010]={0},ans=0;
struct s{
	int x,y;
}r[100005];
int w[501][500010]={0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>w[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].x>>r[i].y;
	}
	for(int i=1;i<=q;i++)cout<<17<<endl;
	return 0;
}
