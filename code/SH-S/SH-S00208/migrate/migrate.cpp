#include<bits/stdc++.h>
using namespace std;
int a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c=12){
		int n,d;
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			if(d==3){
				cout<<max(n-3,0)<<endl;
				continue;
			}
			if(d%2){
				cout<<0<<endl;
				continue;
			}
			cout<<max(n-d*2+2,0)<<endl;
		}
	}
	if(c==13||c==14){
		int n,d;
		while(t--){
			cin>>n>>d;
			int ind=0,cnt=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++)
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					ind=i;
					cnt++;
				}
			for(int i=1;i<=n;i++){
				
			}
		}
	}
	int n,d;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				if(a[j]-a[i]<=d)
					continue;
				if(j==i+3)
					if((a[i+1]-a[i])<=d&&(a[j]-a[j-2])<=d&&(a[i+2]-a[i])<=d&&(a[j]-a[j-1])<=d)
						ans++;
				else{
					int zd=0;
					for(int k=i+1;k<=j-1;k++){
						if((a[k]-a[i])<=d&&(a[j]-a[k])<=d)
							zd++;
						if(zd>=3)
							break;
					}
					if(zd==2)
						ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
