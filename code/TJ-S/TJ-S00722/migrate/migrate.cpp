#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,t,c,k;
long long d;
long long a[N];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin.tie(0);
	
	cin>>c>>t;
	
	while(t--){
		if(n==1){
			cout<<0;
			continue;
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bool f=true;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				f=false;
				k=i-1;
				break;
			}
		}
		if(f){
			int cnt=a[2]-a[1];
			if(d>=2*cnt&&d<cnt*3) cout<<n-3;
			else cout<<0;
		}
		else{
			int cnt=a[k]-a[k-1];
			if(d>=2*cnt&&d<cnt*3) cout<<k-3;
			else cout<<0;
		}
	}
	return 0;
} 
