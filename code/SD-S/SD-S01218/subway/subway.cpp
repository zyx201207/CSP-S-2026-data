#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point{
	int ls,nx,xl,id;
}pt[500005];
int c,n,m,d,q;
int w[500005],k,a[500005][500005],t[500005][50005];
int r;
ll sum;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		sum+=w[x];
		int now=x;
		while(now!=y){
		}
	}
	return 0;
}
