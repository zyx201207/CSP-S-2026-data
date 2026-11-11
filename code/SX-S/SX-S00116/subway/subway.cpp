#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const int N=505000;
ll cc,n,m,d,q;
ll w[N],a[550][3005],t[550][3005];
ll k[N],tong[N];
vector<pll> vt[N];
bool vis[N],f[N];
ll dis[N],c[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j],c[a[i][j]]+=t[i][j],tong[a[i][j]]++;
	}
	if(n==2){
		ll zhz=0;
		for(int i=1;i<=m;i++){
			if(tong[i]==2){
				zhz=i;
				break;
			}
		}
		for(int l=1;l<=q;l++){
			ll x,y,sum=0;
			cin>>x>>y;
			sum+=w[x]+w[y];
			ll xx,yx;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==x) xx=i,sum+=t[i][j];
					if(a[i][j]==y) yx=i,sum+=t[i][j];
				}
				if(xx==yx) break;
			}
			if(xx==yx) cout<<sum<<"\n";
			else cout<<sum+c[zhz]<<"\n";
		}
	}
	
	return 0;
}
