#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e3+10;
const ll inf=0x3f3f3f3f;
ll c,n,m,d,q;
ll a[maxn],f[maxn][maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>a[i];
	}
	memset(f,inf,sizeof(f));
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		f[x1][x2]=f[x2][x1]=y1+y2; 
	} 
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			} 
		} 
	}
	while(q--){
		ll ans=0;
		ll x,y;
		cin>>x>>y;
		ans=f[x][y]+a[x]+a[y];
		cout<<ans<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
