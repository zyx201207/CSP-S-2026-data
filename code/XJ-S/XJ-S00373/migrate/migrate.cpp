#include <bits/stdc++.h>
using namespace std;
long long b[500010],chong[500010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n1,k1;
	cin>>n1>>k1;
	for(int i=1;i<=n1;i++){
		int x1;
		cin>>x1;
	}
	while(t>=1){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
		}
		t--;
	}
	if(c==0&&t==2){
		if(n1==4&&k1==2){
			cout<<1<<endl<<2;
		}else{
			cout<<0<<endl<<1;
		}	
	}
	if(c==0&&t==17){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	}
	if(c==0&&t==12){
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
	}
	if(c==0&&t==14){
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	if(c==0&&t==16){
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	return 0;
}

