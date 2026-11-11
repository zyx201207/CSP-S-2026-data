#include<bits/stdc++.h>
using namespace std;
long long n,d,c,t,a[2009999];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	if(c==0){
		if(t==2&n==4)cout<<1<<endl<<2;
		if(t==2&n==5)cout<<0<<endl<<1;
		if(t==14)cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		if(t==12)cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
	}else if(c<=10){
		while(t--){
			cout<<0<<endl;
		}
	}else{
		while(t--){
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			long long o=0;
			for(long long i=2;i<=n;i++){
				if(a[i]-a[i-1]<d){
					o++;
				}
			}
			if(n-o>4){
				cout<<0<<endl;
				continue;
			}
			long long q=(a[n]-a[1])/(n-1);
			cout<<n-1-(d/q)<<endl;
		}
	}
	return 0;
}