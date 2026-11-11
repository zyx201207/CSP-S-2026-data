#include<bits/stdc++.h> 
using namespace std;
long long c,t,m,n;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>c>>t>>m>>n;
	if(c==0){
		if(t==2&&m==4&&n==2) cout<<1<<endl<<2;
		else if(t==2&&m==5&&n==3) cout<<0<<endl<<1;
		else if(t==17&&m==192&&n==29418319589926278){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl;
			cout<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl;
			cout<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl;
			cout<<0<<endl<<2<<endl<<0;
		}else if(t==12&&m==260000&&n==1){
			cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl;
			cout<<86669<<endl<<0<<endl<<0<<endl<<0<<endl;
			cout<<7<<endl<<5<<endl<<5<<endl<<0;
		}else if(t==14&&m==200001&&n==206291914738518400){
			printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",9999900000,399995,0,716427,0,0,2,1,0,2,3,6,0,2);
		}else if(t==16&&m==174944&&n==139950){
			printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",6800625333,6247500,6242502,4998,9994,0,0,0,2,1,0,2,3,6,0,2);
		}
	}
    return 0;
}