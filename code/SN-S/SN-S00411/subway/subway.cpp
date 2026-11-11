#include <bits/stdc++.h>
using namespace std;
long long w[500005],a[500005],t[500005],x[500005],y[500005],cnt[500005];
int main(){	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=2*n;i++){
		int k;
		cin>>k;
		cin>>a[i]>>t[i];
	}
	for(int i=1;i<=2*q;i++){
		cin>>x[i]>>y[i];
	}
	
	for(int i=1;i<=q;i++){
		cnt[i]=w[i]+t[i];
	}
	
	for(int i=1;i<=q;i++){
		cout<<cnt[i];
	}
	return(0);
}
