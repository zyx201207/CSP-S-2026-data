#include <bits/stdc++.h>
using namespace std;
long long a[2000005],b[2000005],e[2000005],c,t,n,d;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int T=0;T<t;T++){
		cin>>n>>d;
		long long ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=n-1;i>0;i--){
			b[i]=a[i]-a[i-1];
//			cout<<b[i]<<' ';
		}
		for(int i=1;i<n;i++){
			e[i]=e[i-1]+b[i];
//			cout<<e[i]<<' ';
		}
		long long x=0,p=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((e[j]-e[i])>(d-1)&&(e[j]-e[i])%d==(d-1)){
					ans++;
//					cout<<i+1<<' '<<j+1<<endl;
				}
					
			}
				
		}
		cout<<ans<<endl;
		for(int i=0;i<n;i++){
			a[i]=0;b[i]=0;
		}
	}

	return 0;
}
