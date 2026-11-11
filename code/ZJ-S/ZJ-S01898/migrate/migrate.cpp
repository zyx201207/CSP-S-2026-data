#include<bits/stdc++.h>
using namespace std;
long long d,a[2000010],f[2000010],ans;
int c,t,n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			f[i]=a[i]+f[i-1];
		}
		for(int i=2;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int sum=0;
				for(int k=i;k<=j;k++){
					if(a[k]+a[k+1]<=d&&k+1<=j){
						sum++;
					}
				}
				if(sum==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
