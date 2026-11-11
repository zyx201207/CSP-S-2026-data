#include<bits/stdc++.h>
using namespace std;
const int M=2e4+5,N=505,Q=1e5+5;
typedef long long ll;
ll c,n,m,d,q,w[M],r[Q][2];
struct uct{
	ll s,t;
}a[N][M*2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	ll k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;i<=k*2;j++){
			cin>>a[i][j].s>>a[i][j].t;
		}
	}
	for(int i=1;i<=n;i++) cin>>r[i][1]>>r[i][2];
	for(int i=1;i<=n;i++){
		cout<<w[r[i][1]]+w[r[i][2]];
	}
	return 0;	
} 
