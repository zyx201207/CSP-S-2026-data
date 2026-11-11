#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[2000010],p;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		p=x[n]-x[n-1];
		if(2*p<=d&&d<3*p){
			cout<<n-3<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}
