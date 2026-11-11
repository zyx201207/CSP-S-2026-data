#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=505,M=5e5+5;
int c,n,m,d,q,x[M],y[M];
int k[N],t[N];
ll w[M],tt[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>t[i]>>tt[i];
			sum+=tt[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		ll ans=w[x[i]]+w[y[i]];
		cout<<ans+sum<<'\n';
	}
	
	return 0;
}