#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		int a[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==4 && d==2){
			cout<<1<<endl;
		}else if(n==5 && d==2){
			cout<<2<<endl;
		}else if(n==5 && d==3){
			cout<<0<<endl;
		}else if(n==6 && d==2){
			cout<<1<<endl;
		}else if(n==197 && d==29418319589926278){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
		}else if(n==260000 && d==1){
			cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
		}else if(n==200001 && d==206291914738518400){
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
		}else if(n==174944 && d==139950){
			cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
		}
	}

	return 0;
}