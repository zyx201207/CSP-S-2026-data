#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0] and a2[1]==b2[1]){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if(a2[2]<='C' and b2[2]<='C' or a2[2]>'C' and b2[2]>'C'){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(a2[2]=='D' and b2[2]=='F' or a2[2]=='F' and b2[2]=='D'){
		cout<<'1';
	}else if(a2[2]=='D' and b2[2]=='C' or a2[2]=='C' and b2[2]=='D'){
		cout<<'0';
	}else if(abs(a2[2]-b2[2])==1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}