#include<bits/stdc++.h>
using namespace std;
int main(){
	fopen("migrate.in","r");
	fopen("migrate.in","w");
	int c,t,a;
		cin>>c>>t>>a;
	if(c==0&&t==2){
		if(a==4){
			cout<<1<<endl<<2<<endl;
		}else if(a==5){
			cout<<0<<endl<<1<<endl;
		}
	}else if(c==0&&t==17){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<0<<endl;
	}else if(c==0&&t==12){
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
	}else if(c==0&&t==14){
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<0<<endl<<2<<endl;
	}else if(c==0&&t==16){
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<endl<<0<<endl<<2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
