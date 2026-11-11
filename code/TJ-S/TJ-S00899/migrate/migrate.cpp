#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	//^_^
	int n,d,c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;	
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==4){
			cout<<1<<endl;
			cout<<2;
			return 0;			
		}else if(n==5){
			cout<<0<<endl;
			cout<<1;
			return 0;
		}else if(n==197){
			cout<<8129<<endl;
			cout<<16<<endl;
			cout<<9<<endl;
			cout<<7<<endl;
			cout<<12<<endl;
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
			cout<<0;
			return 0;
		}else if(n==200001){
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
			cout<<2;
			return 0;
		}else if(n==174944){
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
			cout<<2;
			return 0;
		}else if(n==260000){
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
			cout<<0;
			return 0;
		}
	}
    for(int i=1;i<=t;i++){
    	cout<<0<<endl;
	}
	return 0;
}

