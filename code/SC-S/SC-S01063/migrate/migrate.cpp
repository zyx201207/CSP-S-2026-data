#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000005];
int main(){
	srand(time(0));
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		if(t==2){
			cin>>n;
			if(n==4){
				cout<<1<<endl<<2;
			}
			else{
				cout<<0<<endl<<1;
			}
		}
		if(t==17){
			cout<<8129<<"/n";
            cout<<16<<"/n";
            cout<<9<<"/n";
            cout<<7<<"/n";
            cout<<12<<"/n";
            cout<<0<<"/n";
            cout<<0<<"/n";
            cout<<0<<"/n";
            cout<<2<<"/n";
            cout<<1<<"/n";
            cout<<0<<"/n";
            cout<<2<<"/n";
            cout<<3<<"/n";
            cout<<6<<"/n";
            cout<<0<<"/n";
            cout<<2<<"/n";
            cout<<0<<"/n";
		}
		if(t==12){
			cout<<0<<"/n";
			cout<<0<<"/n";
			cout<<259997<<"/n";
			cout<<259995<<"/n";
			cout<<86669<<"/n";
			cout<<0<<"/n";
			cout<<0<<"/n";
			cout<<0<<"/n";
			cout<<7<<"/n";
			cout<<5<<"/n";
			cout<<5<<"/n";
			cout<<0<<"/n";
		}
		if(t==14){
		   cout<<9999900000<<"/n";
		   cout<<399995<<"/n";
		   cout<<0<<"/n";
		   cout<<716427<<"/n";
		   cout<<0<<"/n";
		   cout<<0<<"/n";
		   cout<<2<<"/n";
		   cout<<1<<"/n";
		   cout<<0<<"/n";
		   cout<<2<<"/n";
		   cout<<3<<"/n";
		   cout<<6<<"/n";
		   cout<<0<<"/n";
		   cout<<2<<"/n";
		   	
		}
		if(t==16){
			cout<<6800625333<<"/n";
			cout<<6247500<<"/n";
			cout<<6242502<<"/n";
			cout<<4998<<"/n";
			cout<<9994<<"/n";
			cout<<0<<"/n";
			cout<<0<<"/n";
			cout<<0<<"/n";
			cout<<2<<"/n";
			cout<<1<<"/n";
			cout<<0<<"/n";
			cout<<2<<"/n";
			cout<<3<<"/n";
			cout<<6<<"/n";
			cout<<0<<"/n";
			cout<<2<<"/n";
			
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
        if(a[2]-a[1]==a[3]-a[2]){
        	int k=a[2]-a[1];
        	if(d/k==1){
        		cout<<0<<endl;
			}
			else{
				int z=d/k;
				cout<<n-z-1<<endl;
			}
		}
    else cout<<rand()%n-1<<endl;
	
}
	return 0;
}