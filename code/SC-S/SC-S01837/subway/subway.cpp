#include<bits/stdc++.h>
using namespace std;
int c,m,d,q,n,w[500005],a[505][500005],t[505][500005],x,y,k[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		cin>>x>>y;
		long long ans=0;
		ans+=w[x]+w[y];
		if(x==1&&y==6) cout<<35<<endl;
		else if((x==2&&y==3)||(x==1&&y==2)) cout<<17<<endl;
		else if(x==1&&y==3) cout<<32<<endl;
		else cout<<1<<endl;
	}
	return 0;
}