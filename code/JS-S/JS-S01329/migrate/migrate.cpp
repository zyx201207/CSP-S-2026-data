#include<bits/stdc++.h>
using namespace std;
long long n,d,c,t,ans;
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
		if(a[n]-a[1]<=d){
			cout<<0<<endl;
			continue;
		}
		long long k=a[2]-a[1];
		if(d<=k){
			cout<<0<<endl;
			continue;
		}	
		long long cnt=d/k;
		long long minn=3;
		if(cnt==1){
			cout<<0<<endl;
			continue;
		}
		if(cnt==2){
			cout<<n-cnt-1<<endl;
			continue;
		}
		if(cnt==3){
			cout<<n-5<<endl;
			continue;
		}
		if(cnt>3){
			cout<<n-2*cnt+1<<endl;
			continue;
		}
		cout<<n-max(cnt,minn)<<endl;
	}
	return 0;
}
