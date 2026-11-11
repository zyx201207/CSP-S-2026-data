#include <bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2,ans="";
int c1,c2;string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> b1 >> a2 >> b2;
	for(int i=0;i<2;i++){
		c1=c1*10+a1[i]-48;
		c2=c2*10+a2[i]-48;
	}
	if(c1==c2){
		ans+="1";
	}else{
		cout << "0000";
		return 0;
	}
	c1=0;c2=0;
	for(int i=0;i<3;i++){
		if(i<2){
			c1=c1*10+b1[i]-48;
			c2=c2*10+b2[i]-48;
		}else{
			s1=b1[i];
			s2=b2[i];
		}
	}
	if(c1==c2){
		ans+="1";
	}else{
		ans+="000";
		cout << ans;
		return 0;
	}
	if(s1=="D"){
		if(s2=="F"){
			ans+="1";
		}else{
			ans+="00";
			cout << ans;
			return 0;
		}
	}else if(s1=="F"){
		if(s2=="D"){
			ans+="1";
		}else{
			ans+="00";
			cout << ans;
			return 0;
		}
	}
	if(s1=="A"){
		if(s2=="B"||s2=="C"){
			ans+="1";
		}else{
			ans+="00";
			cout << ans;
			return 0;
		}
		if(s2=="B"){
			ans+="1";
		}else{
			ans+="0";
			cout << ans;
			return 0;
		}
	}if(s1=="B"){
		if(s2=="A"||s2=="C"){
			ans+="1";
		}else{
			ans+="00";
			cout << ans;
			return 0;
		}
		if(s2=="C"){
			ans+="1";
		}else{
			ans+="0";
			cout << ans;
			return 0;
		}
	}if(s1=="C"){
		if(s2=="A"||s2=="B"){
			ans+="1";
		}else{
			ans+="00";
			cout << ans;
			return 0;
		}
		if(s2=="B"){
			ans+="1";
		}else{
			ans+="0";
			cout << ans;
			return 0;
		}
	}
	cout << ans;
	return 0;
}