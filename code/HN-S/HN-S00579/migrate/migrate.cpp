#include <bits/stdc++.h>
using namespace std;
int c,t,x[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n-2*d+1;i++){
			int l=x[i]+2*d-1;
			for(int j=i+1;j<=n;j++){
				if(l==x[j]){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

