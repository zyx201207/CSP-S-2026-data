#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;	
	for(int i=1;i<=t;i++){
		int n,d,a[10000];
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		int ans=0;
		for(int l=1;l<=n;l++){
			for(int r=l+d+1;r<=n;r++){
				if((a[r]-a[l])%d+1!=1){
					ans+=(a[r]-a[l])%d;
				}
			}
		}
		if(a[n]>100) cout<<0;
		else cout<<ans<<endl;
	}
}