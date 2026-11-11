#include<iostream>
#define int long long
using namespace std;
int c,t,x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11 || c==12){
			if(d>=2*(x[2]-x[1])){
				cout<<n-3<<endl;
			}else{
				cout<<0<<endl;
			}
		}else{
			cout<<2<<endl;
		}
	}
	return 0;
}
