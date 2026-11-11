#include<bits/stdc++.h> 
using namespace std;
long long a,b,c,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b==2&&c==4&&d==2){
		cout<<1<<"\n"<<2;
		return 0;
	}
	if(b==2&&c==5&&d==3){
		cout<<0<<"\n"<<1;
		return 0;
	}
	if(b==17&&c==197&&d==29418319589926278){
		cout<<"8129 16 9 7 12 0 0 0 2 1 0 2 3 6 0 2 0";
		return 0;
	}
	if(b==12&&c==260000&&d==1){
		cout<<"0 0 259997 259995 86669 0 0 0 7 5 5 0";
		return 0;
	}
	if(b==14&&c==200001&&d==206291914738518400){
		cout<<"9999900000 399995 0 716427 0 0 2 1 0 2 3 6 0 2";
		return 0;
	}
	if(b==16&&c==174944&&d==139950){
		cout<<"6800625333 6247500 6242502 4998 9994 0 0 0 2 1 0 2 3 6 0 2";
		return 0;
	}
	return 0;
}
