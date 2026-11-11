#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long c,t,n,d,a[N]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long x=a[2]-a[1];
		if(2*x-1>=d){
			cout<<0<<"\n";
			continue;
		}
		long long u=d/x;
		u*=2;
		if(u>n) cout<<0<<"\n";
		else cout<<n-u+1<<"\n";
	}
	return 0;
} 
