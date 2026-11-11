#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long a[2000005],d,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		long long i=0,j=4;
		while(j<=n){
			ans++;
			i++;
			j=i+4;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

