#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
char b1,d1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>b1>>c>>d>>d1;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	if(b!=d){
		cout<<"1000";
		return 0;
	}
	if((b1<='C'&&d1<='C')||(b1>='D'&&d1>='D')){
		cout<<"111";
		if(int(b1)+1==int(d1)||int(b1)-1==int(d1)) cout<<"1";
		else cout<<"0";
	}else cout<<"1100";
	return 0;
}
