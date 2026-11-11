#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cha=a[2]-a[1];				
		int k=d/cha;
		
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((a[j]-a[i])/cha%k!=0||(a[j]-a[i])/k) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
