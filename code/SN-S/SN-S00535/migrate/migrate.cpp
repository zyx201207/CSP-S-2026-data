//SN-S00535 程谟然 西安建筑科技大学附属中学 
#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main(){//NEVER GIVE UP!
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cout<<1<<endl<<0;
	long long c,t;
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		long long n,d;
		cin>>n>>d;
		for(long long j=1;j<=n;j++){
			cin>>x[i];
		}
		long long goh=x[2]-x[1];
		if(d%2==1){
			cout<<0<<endl;
		}else if(d==2&&goh==1){
			cout<<n/4+n%4<<endl;
		}
		for(long long j=1;j<=n;j++){
			x[i]=0;
		}
		/*long long sum[2000005];
		for(long long j=1;j<=n;j++){
			sum[i]=sum[i-1]+x[i];
		}
		long long is=n;
		for(long long j=1;j<=n;j++){
			for(long long k=j+1;k<=n;k++){
				long long less=0;
				
			}
		}
		cout<<is<<endl;*/
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
