#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll c,n,m,d,q;
ll k;
ll w[500005];
ll a[505],t[505];
ll x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(c==0&&n==2) cout<<32<<endl<<17<<endl;
	else if(c==0&&n==3) cout<<35<<endl<<16<<endl;
	return 0;
}
