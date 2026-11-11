#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1!=c2) ans+="0";
	else ans+="1";
	string cc=s1.substr(0,2);
	string cc2=s2.substr(0,2);
	if(c1==c2){
		if(cc==cc2) ans+="1";
		else ans+="0";
		char k=s1[2],kk=s2[2];
		if(cc==cc2){
			if((k<='C' && kk<='C') || (k>='D' && kk>='D')) ans+="1";
			else ans+="0";
		}else{
			ans+="0";
		}
		if(cc==cc2){
			if((k<='C' && kk<='C') ){
				if(abs(kk-k)==1) ans+="1";
				else ans+="0";
			}else if((k>='D' && kk>='D')){
				ans+="1";
			}else ans+="0";
		}else{
			ans+="0";
		}
		cout<<ans;
	}else{
		cout<<"0000";
	}
	
	return 0;
}
