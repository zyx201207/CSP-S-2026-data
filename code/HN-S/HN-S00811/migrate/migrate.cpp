#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d,a[2000050],ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(a[1]+(n-1)*(a[2]-a[1])==a[n]){
			if(d<(a[2]-a[1])*2){
				cout<<0;
				continue;
			}else{
				for(int i=1;i<=n;i++){
					if(i%2==1)ans+=max(0,(i/2)-1);
					else ans+=max(0,(i/2)-1);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
