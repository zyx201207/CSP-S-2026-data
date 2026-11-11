#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,d;
int a[2000005],vis[2000005];
signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				
				if(abs(a[j]-a[i])<=2*d&&abs(a[j]-a[i])>d&&j!=i+1) {
					
					
					int cnt=0;
					for(int k=i+1;k<=j-1;k++){
						if(a[k]-a[i]<=d&&a[j]-a[k]<=d){
							cnt++;
						}
					}
					if(cnt==2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
