#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	int a=s1[2],b=s2[2];
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(a>=65&&a<=67&&b>=65&&b<=67)||(a>=68&&a<=70&&b>=68&&b<=70)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((a>=65&&a<=67&&b>=65&&b<=67&&abs(a-b)==1)||(a>=68&&a<=70&&b>=68&&b<=70))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
