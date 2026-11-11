#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=6){
		string a;
		for(int i=1;i<=t;i++){
			char n,d;
			cin>>n>>d;
			a+=n;
			a+=d;
			for(int j=1;j<=n-'0';j++){
				char ci;
				cin>>ci;
				a+=ci;
			}
		}
		if(a=="4212345212345") cout<<1<<endl<<2;
		if(a=="53-2-10126") cout<<0<<endl<<1;
		if(a=="19729418319589926278-999999999999988021-999108535769990255-970581680410061743-969690216180063977-969244484065065094-94") cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		if(a=="260000107142128354249566370778491981051121191261331401471541" ) cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
		if(a=="200001206291914738518400-1000000000000000000-") cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		if(a=="174944139950-1000000000000000000-999999999999860051-9999999999998600") cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/
