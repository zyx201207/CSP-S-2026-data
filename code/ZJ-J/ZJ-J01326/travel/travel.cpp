#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int p1=(s1[0]-'0')*10+s1[1]-'0',p2=(s2[0]-'0')*10+s2[1]-'0';
	if(p1==p2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	char ce1=s1[2],ce2=s2[2];
	if((ce1<='C' && ce2<='C') || (ce1>='D' && ce2>='D')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if((ce1>='D' && ce2>='D') || (abs(ce1-ce2)==1)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
