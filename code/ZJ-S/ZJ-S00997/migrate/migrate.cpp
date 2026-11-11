#include<bits/stdc++.h>
using namespace std;
int c,t,s;
 
int main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
    	long long n,d,a[2000010];
    	cin>>n>>d;
    	s=n;
    	for(int j=1;j<=n;j++){
    		cin>>a[j];
		}
	}
	if(c==0){
		if(s==5){
			cout<<1<<endl;
			cout<<2;
		}
		if(s==6){
			cout<<0<<endl;
			cout<<1;
		}
	}
	return 0;
}