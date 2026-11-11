#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y;
long long w[500005];
struct P{
	long long k;
	long long z[1000005];
}a[505];
int main(){
  	freopen("crystal.in","a",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		for(int j=1;j<=a[i].k*2;j++) cin>>a[i].z[j];
	}
	while(q--){
		cin>>x>>y;
		long long oo=0;
		for(int i=1;i<=m;i++)
			oo+=w[i];
		cout<<oo<<"\n";
	}
	return 0;
}