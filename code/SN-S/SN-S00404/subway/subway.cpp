#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500+5,maxm=5e5+5;
int c,n,m,d,q,w[maxm],k[maxn],a[maxn][maxm],t[maxn][maxm];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
