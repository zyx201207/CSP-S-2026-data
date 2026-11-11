#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int minn=1e9;
				int sl=1;
				for(int g=i+1;g<=j;g++){
					if(x[g]-x[i]<=d&&x[j]-x[g]<=d&&x[g]-x[i]+x[j]-x[g]==minn){
						sl++;
					}else if(x[g]-x[i]<=d&&x[j]-x[g]<=d&&x[g]-x[i]+x[j]-x[g]<minn){
						sl=1;
						minn=x[g]-x[i]+x[j]-x[g];
					}
				}
				if(sl==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

