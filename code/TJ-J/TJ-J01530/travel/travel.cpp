#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans;
	if(c1==c2) {
		ans+='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+='1';
			char n=s1[2],m=s2[2];
			if(m>n) swap(n,m);
			if((m=='A'&&n=='B')||(m=='B'&&n=='C')||(m=='A'&&n=='C')||(m=='D'&&n=='F')){
				ans+='1';
				if(n-m==1) ans+='1';
				else ans+='0';
			}
			else ans+="00";
		}
		else ans+="000";
	}
	else ans+="0000";
	cout<<ans;
	return 0;
} 
