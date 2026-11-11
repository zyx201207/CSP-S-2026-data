#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long x[2000009];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		long long ans=0;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		for(long long i=1;i<=n-d;i++){
			ans+=1;
		}
		cout<<ans-(n-3)<<endl;
	}
	return 0;
} 
