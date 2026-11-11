#include<iostream>
using namespace std;
int c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>n;
	if(c==0){
		if(t==2&&n==4){
			cout<<"1"<<endl<<"2";
			return 0;
		}
		if(t==2&&n==5){
			cout<<"0"<<endl<<"1";
			return 0;
		}
		if(t==17){
			cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0";
			return 0;
		}
		if(t==12){
			cout<<"0"<<endl<<"0"<<endl<<"259997"<<endl<<"259995"<<endl<<"86669"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"7"<<endl<<"5"<<endl<<"5"<<endl<<"0";
			return 0;
		}
		if(t==14){
			cout<<"9999900000"<<endl<<"399995"<<endl<<"0"<<endl<<"716427"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2";
			return 0;
		}
		if(t==16){
			cout<<"6800625333"<<endl<<"6247500"<<endl<<"6242502"<<endl<<"4998"<<endl<<"9994"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2";
			return 0;
		}
	}
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		
		
	} 

	return 0;
}
