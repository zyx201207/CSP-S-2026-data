#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000005],f[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,flag=1,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=2)f[i-1]=a[i]-a[i-1];
			if(i>=3&&f[i-1]!=f[i-2])flag=0;
		}
		if(flag==1){
			if(d<2*f[1])cout<<0<<'\n';
			else{
				for(int i=d/f[1]+2;i<=(d/f[1])*2;i++){
					ans+=(n-i+1);
					cout<<i<<'\n';
				}
				cout<<ans<<'\n';
			}
			
		}
	}
	return 0;
}
