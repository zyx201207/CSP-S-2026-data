#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n%2==1&&d%2==1){
			cout<<0<<endl;
		}else cout<<n/d<<endl;
	}
	return 0;
}

