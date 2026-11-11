#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,ans=0;
		cin>>n>>d;
		long long x[200006]={};
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(x[i]-x[j]<=d))ans++;
			}
		}
		ans/=n;
		cout<<ans/2<<endl;
	}
	return 0;
}
