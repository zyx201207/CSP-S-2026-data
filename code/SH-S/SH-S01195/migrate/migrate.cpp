#include<bits/stdc++.h>
using namespace std;
long long d,a[5010],c,t,n,minn,k=1,zuduan,ans=0;
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		zuduan=n;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			if(a[i+1]-a[i]>d) zuduan=min(zuduan,i);
		}
		for(long long i=d;i<=zuduan;i++){
			if(a[i]+a[1]<=d) continue;
			if(((a[i]+a[1])%d!=0)&&((a[i]+a[1])%(d-1)!=0)) ans++;
		}
		cout<<ans<<endl;
	}
}
