#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],fn,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		fn=x[2]-x[1];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((x[j]-x[i])%d&&(x[j]-x[i])/d==(d/2)){
					ans=ans+(x[j]-x[i])/d;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

