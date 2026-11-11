#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int zw1,zw2,zw3,zw4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	zw1=(b[0]-'0')*10+b[1]-'0';
	zw2=(d[0]-'0')*10+d[1]-'0';
	if(zw1==zw2){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	zw3=b[2]-'A';
	zw4=d[2]-'A';
	if(zw3>=0&&zw3<=2&&zw4>=0&&zw4<=2||zw3>=3&&zw3<=4&&zw4>=3&&zw4<=4){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(abs(zw3-zw4)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
