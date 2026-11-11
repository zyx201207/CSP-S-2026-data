#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((x[j]-x[i])%2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}