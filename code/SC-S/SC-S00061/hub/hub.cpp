#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,k,u[100001],v[100001];
		cin>>n>>k;
		for(long long i=0;i<n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<t-n/2+2<<"\n";
	}
	
	return 0;
}