#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000200];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				bool flag=true;
				int t=0;
				for(int k=i+1;k<=j;k++){
					if(a[k]-a[i]<=d){
						t++;
					}
					if(a[k]-a[k-1]>d) flag=false;
					if(t>=3) flag=false;
				}
				if(flag) {
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
