#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((c1==c2)&&s1.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((c1==c2)&&s1.substr(0,2)==s2.substr(0,2)&&(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((c1==c2)&&s1.substr(0,2)==s2.substr(0,2)&&(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D')&&abs((int)s2[2]-(int)s1[2])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}

