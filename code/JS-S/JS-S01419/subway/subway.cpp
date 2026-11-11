#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	long long cnt=0;
	for(long long i=1;i<=m;i++){
		long long x;cin>>x;
		cnt+=x;
	}
	for(long long i=1;i<=n;i++){
		long long k;cin>>k;
		for(long long j=1;j<=2*k;j++){
			long long x,y;cin>>x>>y;
			cnt+=y;
		}
	}
	while(q--)cout<<cnt<<"\n";
}
