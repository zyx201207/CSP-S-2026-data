#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+='1';
	}
	else{
		ans+="0000";
		cout<<ans;
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2)){
		ans+='1';
	}
	else{
		ans+="000";
		cout<<ans;
		return 0; 
	}
	if((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') || (s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F')){
		ans+='1';
	}
	else{
		ans+="00";
		cout<<ans;
		return 0;
	}
	if(abs(s1[2]-s2[2])==1){
		ans+='1';
	}
	else{
		ans+='0';
	}
	cout<<ans;
	return 0;
} 
