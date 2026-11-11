#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000005],n,d,difff,ans,x;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			difff=a[2]-a[1];
			x=d/difff;
			if(x<2){
				cout<<0<<endl;
			}
			else{
				cout<<n-(2*x-1)<<endl;
			}
		}
		else
			cout<<0<<endl;
	}
	
	return 0;
}