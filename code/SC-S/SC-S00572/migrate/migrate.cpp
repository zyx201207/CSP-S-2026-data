#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		int a[n+1];
		
		cin>>a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			
		}
		
		for(int i=2;i<=n;i++){
			int lxs=1;
			if(a[i]-a[1]<=d){
				continue;
			}
			
			int k=(a[i]-a[1]);
			if((a[i]-a[1])%d>0){
				k++;
			}
			for(int j=1;j<=k;j++){
				int ls=0;
				for(int y=2;y<=n;y++){
					if(a[y]>a[i]&&a[y]<=(a[i]+d)){
						ls++;
					}
				}
				lxs*=ls;
			}
			if(lxs==2){
				ans++;
			}
		}
		cout<<ans<<"\n";
		
	}
	
	return 0;
}
