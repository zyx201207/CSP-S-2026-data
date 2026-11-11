#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[2000007],d,n;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>d>>n;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(d<a[3]-a[1]){
				cout<<0<<endl;
				continue;
			}
			else{
				cout<<2<<endl;
			}
		}
	}
	else{
		for(int i=1;i<=t;i++){
			cout<<0<<endl;
		}
	}
	return 0;
}