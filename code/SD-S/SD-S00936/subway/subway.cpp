#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	ll p[m+1];
	for(ll i=1; i<=m; i++) {
		cin>>p[i];
	}
	ll xl[q+1][1000010];
	ll subway[n+1][21]= {0};
	for(ll r=1; r<=n; r++) {
		cin>>xl[r][1];
		for(ll j=1; j<=xl[r][1]; j++) {
			cin>>xl[r][2*j]>>xl[r][2*j+1];
		}
		for(ll x=1; x<=xl[r][1]; x++) {
			for(ll h=1; h<=xl[r][1]; h++) {
				subway[2*x][2*h]=1;
				subway[2*h][2*x]=1;
			}
		}
	}
	ll jh[q+1][3];
	for(ll i=1; i<=q; i++) {
		cin>>jh[i][1]>>jh[i][2];
		ll cnt=0,jg=1;
		ll s=2;
		ll un[q+1];
		while(cnt==0) {
			un[1]=jh[i][1];
			for(ll y=1; y<=s-1; y++) {
				if(subway[un[y]][jh[i][2]]==1) {
					cout<<p[jh[q+1][1]]+p[jh[q+1][2]]+jg*xl[1][3]<<endl;
					cnt++;
					y=s+1;
				}
			}
			for(ll k=1; k<=m; k++) {
				ll po=un[s];
				ll g=s;
				for(ll h=1; h<=g; h++) {
					if(subway[po][k]==1) {
						un[s]=k;
						s++;
					}
				}
			}
			jg++;
		}
	}
	return 0;
}
