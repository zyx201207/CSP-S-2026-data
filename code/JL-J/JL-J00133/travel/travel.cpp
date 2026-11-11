#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	char b1,b2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	   cout<<1;
	}else{
	   cout<<"0000";
	   return 0;
	}
	b1=s1[2];
	s1[2]='0';
	b2=s2[2];
	s2[2]='0';
    if(s1==s2){
		cout<<1;
		if(b1>='A'&&b1<='C'&&b2>='A'&&b2<='C'){
			cout<<1;
			if((b1=='A' && b2=='C') || (b1=='C' && b2=='A')){
				cout<<0;
			}else{
				cout<<1;
			}
		}else if((b1=='D' || b1=='F') && (b2=='D' || b2=='F')){
			cout<<"11";
			return 0;
		}else{
		    cout<<"00";
		    return 0;
		}
	}else{
		cout<<"000";
		return 0;
	}
	return 0;
}
