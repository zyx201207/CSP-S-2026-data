//刘曌珩  SN-J00817  西安市含光中学 
#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0; 
	}
	if(a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]&&((b[2]-'A'<=2&&d[2]-'A'<=2)||(b[2]-'A'>2&&d[2]-'A'>2))){
		cout<<"1";
	}
	else{
		cout<<"00";	
		return 0;
	}
	if(a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]&&((b[2]-'A'<=2&&d[2]-'A'<=2&&abs((b[2]-'A')-(d[2]-'A'))==1)||(b[2]-'A'>2&&d[2]-'A'>2&&abs((b[2]-'A')-(d[2]-'A'))==2))){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;	
	}
	return 0;
}
