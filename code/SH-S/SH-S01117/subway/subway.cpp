#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int c,n,m,d,q,ans,x,y;
int w[N],k[N],a[N][N],t[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
	}
	}
	
	for(int ii=1;ii<=q;ii++){
		cin>>x>>y;
		ans=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
