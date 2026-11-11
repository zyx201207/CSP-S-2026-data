#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
bool f;
signed main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2){
		
		if(c1.length()!=c2.length()) f=1;
		else{
			for(int i=0;i<c1.length()-1;i++){
				if(c1[i]!=c2[i]) f=1;
			}
		}
		
		if(f==1){
			cout<<"1000";return 0;
		}
		else{
			
			char ca=c1[c1.length()-1],cb=c2[c2.length()-1];
			if((ca<='C'&&cb<='C')||(ca>='D'&&cb>='D')){
				if(abs(int(ca)-int(cb))==1||(ca=='D'&&cb=='F')||(ca=='F'&&cb=='D')) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
	}
	else{
		cout<<"0000";return 0;
		
	}
	return 0;
}
