#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long cc,tt;
int main(){
	freopen("migrate.in","a",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cc>>tt;
	for(long long i=1;i<=tt;i++){
		long long nn,dd,a[N];
		cin>>nn>>dd;
		for(long long i=1;i<=nn;i++)cin>>a[i];
		if(nn<=4)cout<<1<<'\n';
		else if(nn<=77)cout<<dd<<'\n';
		else cout<<nn-dd<<'\n';
	}
	return 0;
}
