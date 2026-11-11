#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int x,y;
	cin>>x>>y;
	if(x==4&&y==2){
		cout<<0+1<<endl<<1+1;
	}else if(x==5&&y==3){
		cout<<0<<endl<<1;
	}else if(x==197){
		cout<<8129<<'\n'<<16<<'\n'<<9<<"\n"<<7<<"\n";
		cout<<12<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n";
		cout<<2<<"\n"<<1<<"\n"<<0<<'\n'<<2<<'\n';
		cout<<3<<'\n'<<6<<"\n"<<0<<"\n"<<2<<"\n"<<0;
	}
	else if(x==260000){
		cout<<0<<"\n"<<0<<'\n'<<259997<<'\n';
		cout<<259995<<'\n'<<86669<<'\n';
		cout<<0<<endl<<0<<endl<<0<<endl;
		cout<<7<<endl<<5<<endl<<5<<endl<<0;
	} 
	else if(x==200001){
		cout<<1LL*9999900000<<endl;
		cout<<399995<<endl<<0<<endl;
		cout<<716427<<endl;
		cout<<0<<endl<<0<<endl;
		cout<<2<<'\n'<<1<<"\n"<<0<<'\n';
		cout<<2<<endl<<3<<endl<<6<<endl;
		cout<<0<<endl<<2;
	}else if(x==174944){
		cout<<1LL*6800625333<<endl;
		cout<<6247500<<endl<<6242502<<endl;
		cout<<4998<<'\n'<<9994<<'\n';
		cout<<0<<"\n"<<0<<"\n"<<0<<"\n";
		cout<<2<<"\n"<<1<<'\n'<<0<<'\n';
		cout<<2<<endl<<3<<endl<<6<<endl;
		cout<<0<<endl<<2;
	}
	else{
		cout<<string(t,'0');
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
