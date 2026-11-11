#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int c,n,m,d,q,w[maxn],k[maxn],a[505][505],t[505][505],x,y,ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
