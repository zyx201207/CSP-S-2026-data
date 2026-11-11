#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
	 	}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]>=2*d){
					break;
				}
				if(a[j]-a[i]<=d){
					continue;
				}
				int sum=0;
				for(int k=i+1;k<j;k++){
					if(a[k]-a[i]<=d&&a[j]-a[k]<=d){
						sum++;
					}
				}
				if(sum==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
