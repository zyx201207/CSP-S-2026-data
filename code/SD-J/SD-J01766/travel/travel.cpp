#include <bits/stdc++.h>
using namespace std ;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		ans += "0000" ;
	}
	else{
		ans += '1' ;
		if(s1[0]+s1[1]!=s2[0]+s2[1]){
			ans += "000" ;
		}
		else{
			ans += '1' ;
			if(((s1[2]<='C'&&s1[2]>='A')&&(s2[2]<='C'&&s2[2]>='A'))
			||(s1[2]<='F'&&s1[2]>='D')&&(s2[2]<='F'&&s2[2]>='D')){
				ans += '1' ;
				char a = s1[2] ;
				char b = s2[2] ;
				if(char(int(a)+1)==b||char(int(b)+1)==a) ans += '1' ;
				else ans += '0' ;
			}
			else ans += "00" ;
		}
	}
	cout<<ans;
	return 0 ;
} 
