#include<bits/stdc++.h>
using namespace std;
int c,t,n,cnt;
long long d,x[2000005],ans;
bool b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)scanf("%d",&x[i]);
		if(n<3){
			cout<<0<<'\n';
			continue;
		}
		long long m=x[2]-x[1];
		for(int i=3;i<=n;i++){
			if(x[i]-x[i-1]!=m){
				b=1;
				break;
			}
		}
		if(!b){
			if(d<m*2){
				cout<<0<<'\n';
				continue;
			}
			long long p=d/m;
			long long a=(n-p)/p;
			ans=a*a*(p-1)*p/2+(n%p)*(a*(p-1)*2+n%p-1)/2;
			cout<<ans<<'\n';
		}
		
	}
	return 0;
}
