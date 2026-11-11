#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>a[i];
		int flag=0;
		long long k=a[2]-a[1];
		if(k>d){
			cout<<0<<"\n";
			continue;
		}
		for(int i=3;i<=n;++i){
			if(a[i]!=a[i-1]+k){
				flag=1;
				break;
			}
		}
		if(flag==0){
			if(d<3*k&&d>=2*k){
				cout<<n-3<<"\n";
			}
			else if(d<4*k&&d>=3*k){
				cout<<n-5<<"\n";
			}
			else{
				cout<<0<<"\n";
			}
		}
	}
	return 0;
} 