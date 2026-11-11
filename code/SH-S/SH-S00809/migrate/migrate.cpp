#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int c;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		c=a[n]-a[n-1];
		if(d<c*2){
			cout<<0<<endl;
			continue;
		}
		if(d==c*2){
			cout<<n-4+1<<endl;
			continue;
		}
	}
	return 0;
}
