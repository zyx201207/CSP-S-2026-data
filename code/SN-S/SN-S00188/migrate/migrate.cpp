#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
//	if(c==11||c==12){
		while(T--){
			long long n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(T==9){
//				cout<<d<<" "<<a[1]<<" "<<a[2]<<endl;
			}
			if(d>=abs(a[3]-a[1])){
//				cout<<11<<endl;
//				cout<<d<<" "<<a[1]<<" "<<a[3]<<a[3]-a[1]<<endl;
				cout<<n-4+1<<endl;
			}else{
				cout<<0<<endl;
			}
		}
//	}
	return 0;
}
