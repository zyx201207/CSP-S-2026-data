#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,w[500005],k,a[505][50005],t[505][50005],trip_st[100005],trip_ed[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>trip_st[i]>>trip_ed[i];
	}
	for(ll i=1;i<=q;i++){
		cout<<w[trip_st[i]]+w[trip_ed[i]]+t[1][trip_st[i]]+t[1][trip_ed[i]]<<"\n";
	}
	return 0;
}
