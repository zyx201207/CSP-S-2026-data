#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[200002];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long y[200002]={0},ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=i+d-1;j++){
				int a=j;
				for(int k=j;k<=n;k+=d){
					if(x[k]==x[a]+d){

						y[k]++;
					}
					a=k;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(y[i]==2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}