#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000081],vis[2000081];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		long long dis=a[2]-a[1];
		dis=d/dis+d/dis/2+1;
		cout<<n-dis+1<<endl;
	}
}
