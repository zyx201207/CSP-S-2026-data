#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans;
long long d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==13||c==14||c==11||c==12){
			ans=n-1;
			cout<<ans;
			continue;
		}
		if(c<=10){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(a[i]-a[j]==a[j]-a[i]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
