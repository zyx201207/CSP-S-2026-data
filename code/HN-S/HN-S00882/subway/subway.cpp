#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
ll c,n,m,d,q;
ll w[N];
ll maxx=-1e18;
struct road{
	ll z;
	ll a[N];
	ll t[N];
}r[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>r[i].z;
		for(int j=1;j<=r[i].z;j++){
			cin>>r[i].a[j];	
			cin>>r[i].t[j];	
		}
	}
	for(int i=1;i<=q;i++){
		ll A,B;
		cin>>A>>B;
		cout<<w[A]+w[B];
	}
	return 0;
}
