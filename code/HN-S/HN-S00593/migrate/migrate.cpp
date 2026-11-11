#include<bits/stdc++.h>
using namespace std;
long long o,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>o>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d>a[2]-a[1]){
			cout<<n-(d+1)<<endl;
			break;
		}
	}
	
	
	
	return 0;
} 
