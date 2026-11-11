#include<bits/stdc++.h>
using namespace std;
long long c,t,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;
	cin>>t;
		while(t--){
			long long n,d;
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
				cin>>x[i];
			} 
			long long s=x[2]-x[1];
			long long anss=d/s;
			int ans=anss*2;
			cout<<n-ans+1<<endl;
		}
	return 0;
}
