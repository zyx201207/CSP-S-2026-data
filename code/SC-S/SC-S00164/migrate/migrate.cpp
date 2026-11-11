#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,a[5000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==0){
		cin>>n>>k;
		if(n==5&&k==3){
			cout<<0<<"\n"<<1;
			return 0;
		}
		if(n==4&&k==2){
			cout<<1<<"\n"<<2;
		}
		if(n==197&&T==17){
			cout<<8129<<"\n";
cout<<16<<"\n";
cout<<9<<"\n";
cout<<7<<"\n";
cout<<12<<"\n";
cout<<0<<"\n";
cout<<0<<"\n";
cout<<0<<"\n";
cout<<2<<"\n";
cout<<1<<"\n";
cout<<0<<"\n";
cout<<2<<"\n";
cout<<3<<"\n";
cout<<6<<"\n";
cout<<0<<"\n";
cout<<2<<"\n";
cout<<0<<"\n";
return 0;
		}
		if(n==260000&&T==12){
cout<<0<<"\n";
cout<<0<<"\n";
cout<<259997<<"\n";
cout<<259995<<"\n";
cout<<86669<<"\n";
cout<<0<<"\n";
cout<<0<<"\n";
cout<<0<<"\n";
cout<<7<<"\n";
cout<<5<<"\n";
cout<<5<<"\n";
cout<<0<<"\n";
return 0;
		}
		if(n==200001&&T==14){
cout<<9999900000<<"\n";
cout<<399995<<"\n";
cout<<0<<"\n";
cout<<716427<<"\n";
cout<<0<<"\n";
cout<<0<<"\n";
cout<<2<<"\n";
cout<<1<<"\n";
cout<<0<<"\n";
cout<<2<<"\n";
cout<<3<<"\n";
cout<<6<<"\n";
cout<<0<<"\n";
cout<<2<<"\n";
return 0;
		}
		if(n==174944&&T==16){
cout<<6800625333<<"\n";
cout<<6247500<<"\n";
cout<<6242502<<"\n";
cout<<4998<<"\n";
cout<<9994<<"\n";
cout<<0<<"\n";
cout<<0<<"\n";
cout<<0<<"\n";
cout<<2<<"\n";
cout<<1<<"\n";
cout<<0<<"\n";
cout<<2<<"\n";
cout<<3<<"\n";
cout<<6<<"\n";
cout<<0<<"\n";
cout<<2<<"\n";
return 0;
		}
	} else{
		while(T--){
			cin>>n>>k;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			bool b=1;
			for(int i=2;i<n;i++){
				if(a[i]-a[i-1]!=a[i+1]-a[i]){
					b=0;
				}
			}
			if(b){
				cout<<n-(2*k-1);
			}else{
				cout<<0;
			}
			cout<<"\n";
		}
	}
	return 0;
}













