#include<bits/stdc++.h>
using namespace std;
int i,j,n;
string a1,a2,b1,b2;
bool c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>a1>>a2>>b1>>b2;
	if(a2[2]=='D'||a2[2]=='F'){
		c1=true;
	}else{
		c1=false;
	}
	if(b2[2]=='D'||b2[2]=='F'){
		c2=true;
	}else{
		c2=false;
	}
	if(a1==b1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(c1==true){
		cout<<1;
		return 0;
	}if((a2[2]=='A'&&b2[2]=='C')||(b2[2]=='A'&&a2[2]=='C')){
		cout<<0;
	}else{
		cout<<1;
	}
	return 0;
}
