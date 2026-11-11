#include<bits/stdc++.h>
using namespace std;

long long c,t;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		long long n,d,c,a[2000002],ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		c=a[2]-a[1];
		ans=1+(a[n]-3*c)/d;
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
