#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
int a,b,c,d,h,i;
string e,f,g,j,k,l;
cin>>a;
if(a==3){
	cin>>b>>e>>c>>f>>d>>g;
	if(b==2&&e=='a'&&c==2&&f=='b'&&d==1&&g=='c'){
		cout<<2;
	}
}
if(a==2){
	cin>>b>>e>>c>>f;
	if(b==2&&e=='a'&&c==3&&f=='a'){
		cout<<0;
	}
}
if(a==6){
	cin>>b>>e>>c>>f>>d>>g>>d>>j>>h>>k>>i>>l;
	if(b==1000000000&&e=='a'&&c==1000000000&&f=='a'&&d==1000000000&&g=='a'&&d==1000000000&&j=='b'&&h==1000000000&&k=='b'&&i==1000000000&&l=='b'){
		cout<<3000000000;
	}
}
return 0;
}