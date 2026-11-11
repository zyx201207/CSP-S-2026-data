#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[500005],m;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		m=a[2]-a[1];
		cout<<n-d/m-1<<'\n';
	}
	return 0;
}
