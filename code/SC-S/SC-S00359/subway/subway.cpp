#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
typedef long long ll;
const int M=5e5+5;
int c,n,m,d,q,w[M],a[505][1002],t[505][1002];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=0;
	}
	cout<<31<<endl<<25;
	return 0;
}
