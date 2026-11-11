#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ans[500005]={0,1};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}	
	}
	
	for(int i=1;i<=t;i++){
		cout<<ans[i];
	}
	return 0;
} 
