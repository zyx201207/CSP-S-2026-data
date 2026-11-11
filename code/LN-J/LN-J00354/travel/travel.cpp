#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2,k;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>a>>c2>>s2>>b;
	if(c1==c2) cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	if(s1==s2) cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	if(a<='C'&&b<='C'){
		cout<<'1';
		if(a+1==b||a-1==b) cout<<'1';
		else cout<<'0';
	}
	else if(a<='F'&&b<='F'&&a>'C'&&b>'C'){
		cout<<"11";
	}
	else{
		cout<<"00";
	}
	//cout<<"11111111111111";
	//puts(" ");
	//cout<<c1<<' '<<s1<<' '<<a<<' '<<' '<<c2<<' '<<s2<<' '<<b;  
	return 0;
}
