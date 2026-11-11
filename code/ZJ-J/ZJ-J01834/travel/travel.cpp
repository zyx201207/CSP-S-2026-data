#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	} 
	int a=(s1[0]-'0')*10+s1[1]-'0',b=(s2[0]-'0')*10+s2[1]-'0';
	char k1=s2[2],k2=s1[2];
	if(a==b){
		cout<<1;
	}
	else {
		cout<<"000";
		return 0;
	}
	if((k1<='C'&&k2<='C')||(k1>'C'&&k2>'c')){
		cout<<1;
	}
	else {
		cout<<"00";
		return 0;
	}
	if(abs(k2-k1)==1){ 
		cout<<1;
	}
	else {
		cout<<"0";
		return 0;
	}
	
	return 0;
}
