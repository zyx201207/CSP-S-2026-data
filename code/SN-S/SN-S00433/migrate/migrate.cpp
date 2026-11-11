//赵晗羽  SN-S00433  西安辅轮中学  
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		k/=a[2]-a[1];
		if(k==1){
			cout<<0<<endl;
		}else{
			int p=n/k,s=0;
			int y=p;
			if(p==1){
				s=1;
				cout<<1<<endl;
			}else{
				cout<<p<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
