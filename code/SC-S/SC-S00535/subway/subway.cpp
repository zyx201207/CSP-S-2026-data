#include<bits/stdc++.h>
using namespace std;
const int maxn=506;
const int maxk=5e5+6;
int c,n,m,d,q,w[maxn],k[maxn];
int a[maxn][maxk],t[maxn][maxk];
int x[maxn],y[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y,ans=0;
		cin>>x>>y;
		for(int i=x;i<=y;i++) ans+=w[i];
		cout<<ans<<endl;
	}
	return 0;
}