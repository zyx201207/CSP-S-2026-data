#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510,M=5e5+10;
const ll INF=1e16;
ll CASE,nLine,nStop,D,Q;
ll dst[N][N];
ll w[M];
struct Node{
	ll line;
	ll dist;
};
vector<Node> station[M];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>CASE>>nLine>>nStop>>D>>Q;
	for (ll i=1;i<=nStop;++i) {
		cin>>w[i];
	}
	for (ll i=1;i<=nLine;++i) {
		ll stops;
		cin>>stops;
		for (ll j=1;j<=stops;++j) {
			ll num,dist;
			cin>>num>>dist;
			station[num].push_back((Node){i,dist});
		}
	}
	for (ll i=1;i<=nLine;++i) {
		for (ll j=1;j<=nLine;++j) {
			dst[i][j]=INF;
		}
		dst[i][i]=0;
	}
	for (ll i=1;i<=nStop;++i) {
		for (Node j:station[i]) {
			for (Node k:station[i]) {
				if (j.line>=k.line) {
					continue;
				}
				dst[j.line][k.line]=min(dst[j.line][k.line],j.dist+k.dist);
				dst[k.line][j.line]=dst[j.line][k.line];
			}
		}
	}
	for (ll k=1;k<=nLine;++k) {
		for (ll i=1;i<=nLine;++i) {
			for (ll j=1;j<=nLine;++j) {
				dst[i][j]=min(dst[i][j],dst[i][k]+dst[k][j]); 
			}
		}
	}
	while (Q--) {
		ll S,T;
		cin>>S>>T;
		ll ans1=w[S]+w[T];
		ll ans2=INF;
		for (Node j:station[S]) {
			for (Node k:station[T]) {
				ans2=min(ans2,j.dist+k.dist+dst[j.line][k.line]);
			}
		}
		cout<<ans1+ans2<<"\n";
	}
	return 0;
}

