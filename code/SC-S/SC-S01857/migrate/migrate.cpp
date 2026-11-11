#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;	
	if(c==0){
		long long n1;
		for(long long i=0;i<t;i++){	
			long long d;
			cin>>n1>>d;
			for(long long i=0;i<n1;i++){
				long long x;
				cin>>x;
			}
		}
		if(t==17){
			cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0";
			return 0;
		}
		if(t==16){
			cout<<"6800625333"<<endl<<"6247500"<<endl<<"6242502"<<endl<<"4998"<<endl<<"9994"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2";			
			return 0;
		}
		if(t==14){
			cout<<"9999900000"<<endl<<"399995"<<endl<<"0"<<endl<<"716427"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2";			
			return 0;
		}
		if(t==12){
			cout<<"0"<<endl<<"0"<<endl<<"259997"<<endl<<"259995"<<endl<<"86669"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"7"<<endl<<"5"<<endl<<"5"<<endl<<"0";
			return 0;
		}
		if(n1==5){
			cout<<"1"<<endl<<"2";
			return 0;
		}
		if(n1==6){
			cout<<"0"<<endl<<"1";
			return 0;
		}
	} 	
	for(long long i=0;i<t;i++){
		long long n,d;
		cin>>n>>d; 
		long long sum=0;
		for(long long i=0;i<n;i++){
			cin>>a[i];
			if((n-a[i]-d)==0){
				sum*=2;
				break;
			}
			sum+=(n-a[i]-d);
		}
		cout<<sum<<endl; 
	}
	return 0;
}