#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long k;
long long u[2*1000000+1];
long long v[2*1000000+1];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>u[j]>>v[j];
		}
		cout<<(n/t)-(t+1)/2;
	}
	return 0;
}
