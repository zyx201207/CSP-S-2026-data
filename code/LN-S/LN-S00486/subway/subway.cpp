#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,n,m,d,q,a[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			int u,w;
			cin>>u>>w;
			a[u]+=w;
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<a[u]+a[v]<<"\n";
	}
	return 0;
}
