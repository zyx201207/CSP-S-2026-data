#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],k[505],a[505],x[500005],y[500005],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		ans+=k[i];
	}
	cout<<ans;
	return 0;
}