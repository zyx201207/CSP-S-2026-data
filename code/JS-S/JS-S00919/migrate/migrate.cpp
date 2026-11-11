#include <bits/stdc++.h>
using namespace std;
int c,t;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		int ans=0;
		for(int j=4;j<=n;j++){
			for(int k=1;k<j;k++){
				if(a[j]-a[k]>d&&1.0*(a[j]-a[k])<=1.5*d) ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
