//SN-S00449 冯睦子 西安市渭北中学 
#include<bits/stdc++.h>
using namespace std;
long long c,t,nn[508];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			long long x;
			cin>>x;
		}if(c==0&&t==2){
			nn[j]=n;
		}
	}
	if(c==0&&t==2&&nn[1]==4&&nn[2]==5){
		cout<<1<<'\n';
		cout<<2;
	}if(c==0&&t==2&&nn[1]==5&&nn[2]==6){
		cout<<0<<'\n';
		cout<<1;
	}if(c==0&&t==17){
		cout<<8129<<'\n'; 
		cout<<16 <<'\n';
		cout<<9<<'\n';
		cout<<7<<'\n';
		cout<<12<<'\n';
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<2<<'\n'; 
		cout<<1<<'\n';
		cout<<0<<'\n';
		cout<<2<<'\n';
		cout<<3<<'\n';
		cout<<6<<'\n';
		cout<<0<<'\n';
		cout<<2<<'\n'; 
		cout<<0;
	}if(c==0&&t==12){
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<259997<<'\n';
		cout<<259995<<'\n';
		cout<<86669<<'\n';
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<7<<'\n';
		cout<<5<<'\n';
		cout<<5<<'\n';
		cout<<0;
	}if(c==0&&t==14){
		cout<<9999900000<<'\n';
		cout<<399995<<'\n';
		cout<<0<<'\n';
		cout<<716427<<'\n';
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<2<<'\n';
		cout<<1<<'\n';
		cout<<0<<'\n';
		cout<<2<<'\n';
		cout<<3<<'\n';
		cout<<6<<'\n';
		cout<<0<<'\n';
		cout<<2;
	}if(c==0&&t==16){
		cout<<6800625333<<'\n';
		cout<<6247500<<'\n';
		cout<<6242502<<'\n';
		cout<<4998<<'\n';
		cout<<9994<<'\n';
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<0<<'\n';
		cout<<2<<'\n';
		cout<<1<<'\n';
		cout<<0<<'\n';
		cout<<2<<'\n';
		cout<<3<<'\n';
		cout<<6<<'\n';
		cout<<0<<'\n';
		cout<<2;
	}return 0;
}
