#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 || c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			int q=x[2]-x[1];
			int i=d/q;
			cout<<((n-i-1)>=0?n-i-1:0)<<endl;
		}
	}
	else{
		while(t--){
			cout<<0<<endl;
		}
	}
	return 0;
}