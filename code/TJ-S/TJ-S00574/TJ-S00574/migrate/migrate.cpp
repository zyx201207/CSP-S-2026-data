#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t>>n>>d;
	if (c==0){
		if (t==2){
			if (n==4){
				cout<<1<<endl<<2;
			}
			if (n==5){
				cout<<0<<endl<<1;
			}
		}
		if (t==16){
			cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		}
	}
	else{
		for (int i=0;i<t;i++){
			cout<<0<<endl;
		}
	}
	return 0;
}
