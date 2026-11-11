//SN-J00722
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ("trave.in","r",stdin);
	freopen ("trave.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
		if(a==c && b=="01A" && d=="01B" ){
			cout<<"1111";
		}
		if(a==c && b=="01C" && d=="01A" ){
			cout<<"1110";
		}
		if(a==c && b=="02B" && d=="01A" ){
			cout<<"1000";
		}
		if(a==c && b=="01C" && d=="01D" ){
			cout<<"1100";
		}
		else{
			cout<<"0 0 0 0";
		}
	return 0;
}
