#include<bits/stdc++.h>

using namespace std;

string a1,b1,c1,c2;
string a2,b2;
int d1,d2;
bool f[]={0,0,0,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	c1=b1[0]+b1[1];c2=b2[0]+b2[1];
	d1=b1[2]-'A';d2=b2[2]-'A';
	if(a1==a2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a1==a2&&c1==c2){
		cout<<1;	
	}else{
		cout<<0;
	}
	if(a1==a2&&c1==c2&&f[d1]==f[d2]){
		cout<<1;	
	}else{
		cout<<0;
	}
	if(a1==a2&&c1==c2&&f[d1]==f[d2]&&abs(d1-d2)==1){
		cout<<1;
	}else{
		cout<<0;
	}
}