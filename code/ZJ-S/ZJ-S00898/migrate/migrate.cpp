#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
long long c,t,ans;

int main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){ 
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(long long j=1;j+2*d-1<=n;j++){		
			long long ma=x[j+2*d-1]-x[j];
				if(ma>d && ma<2*d) {
					ans++;	
				} 
			
		}
		cout << ans << endl;
		ans=0;
		memset(x,sizeof(x),0);
	}
	return 0;
}
