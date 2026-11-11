#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long u[1000005],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		long long n,k;
		cin>>n>>k;
		for(long long j=1;j<=k;j++){
			cin>>u[j]>>v[j];
		}
	}
	return 0;
}
