#include <bits/stdc++.h>
using namespace std;
long long x[2000005];
int main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	long long ans=0;
	long long len=0; 
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		cin>>n>>d;
		for(long long j=1;j<=n;j++){
			cin>>x[j];
			if(j==2){
				len=x[2]-x[1];
				break;
			}
		}
		if(d>=len*2&&d<=len*3){
			ans=n-3;
		}
		cout<<ans<<endl;
		len=0;
		ans=0;
	}
	return 0;
}
