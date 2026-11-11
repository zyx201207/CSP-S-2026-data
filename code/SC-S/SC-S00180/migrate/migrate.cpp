#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,ans;
long long a[2000005]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int z=1;z<=t;z++){
		memset(a,0,sizeof(0));
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=4&&a[i-3]+m>=a[i-2]&&a[i]<=a[i-3]+2*m&&a[i]>a[i-3]+m&&a[i-2]+m>=a[i]&&a[i-1]-m<=a[i-3]){
				ans++;
			}
		}cout<<ans;
	}
}