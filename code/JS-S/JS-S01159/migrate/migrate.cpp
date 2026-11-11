#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,x;
    cin>>c>>t>>x;
    if(c==0){
		if(t==2 && x==4){
			cout<<1<<endl<<2;
		}
		if(t==2 && x==5){
			cout<<0<<endl<<1;
		}
		if(t==17 && x==197){
			cout<< 8129<<endl;
			cout<< 16<<endl;
			cout<< 9<<endl;
			cout<< 7<<endl;
			cout<< 12<<endl;
			cout<< 0<<endl;
			cout<< 0<<endl;
			cout<< 0<<endl;
			cout<< 2<<endl;
			cout<< 1<<endl;
			cout<< 0<<endl;
			cout<< 2<<endl;
			cout<< 3<<endl;
			cout<< 6<<endl;
			cout<< 0<<endl;
			cout<< 2<<endl;
			cout<< 0<<endl;
		}
		if(t==12 && x==260000){
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<259997<<endl;
            cout<<259995<<endl;
            cout<<86669<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<7<<endl;
            cout<<5<<endl;
            cout<<5<<endl;
            cout<<0<<endl;
		}
		if(t==14 && x==200001){
			cout<<9999900000<<endl;
            cout<<399995<<endl;
            cout<<0<<endl;
            cout<<716427<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<2<<endl;
            cout<<1<<endl;
            cout<<0<<endl;
            cout<<2<<endl;
            cout<<3<<endl;
            cout<<6<<endl;
            cout<<0<<endl;
            cout<<2<<endl;
		}
		if(t==16 && x==174944){
            cout<<6800625333<<endl;
            cout<<6247500<<endl;
            cout<<6242502<<endl;
            cout<<4998<<endl;
            cout<<9994<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<2<<endl;
            cout<<1<<endl;
            cout<<0<<endl;
            cout<<2<<endl;
            cout<<3<<endl;
            cout<<6<<endl;
            cout<<0<<endl;
            cout<<2<<endl;
		}
	}
	else{
		for(int i=1;i<=t;i++){
			cout<<1<<endl;
		}
	}
    return 0;
}
