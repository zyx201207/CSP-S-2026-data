#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
long long p[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		int n;
		long long d;
		cin>>n>>d;
		int flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(flag==1){
			int z=a[n]-a[n-1];
			
			if(d>=2*z){
				long long u=d/z*2;
				cout<<n-u+1;
				continue;	
			}
			else if(d<2*z){
				cout<<0<<endl;
				continue; 
			}
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d){
						p[i]=j;
						continue;
					}	
				}
			}
			for(int i=1;i<=n;i++){
				if(p[i]-i<=2)continue;
				else{
					ans+=n/2/(p[i]-i);
				}
			}
			cout<<ans<<endl;
		}
	}
	
} 
