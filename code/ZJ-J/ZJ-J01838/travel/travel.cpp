#include<bits/stdc++.h>
using namespace std;
string c_,s_,c__,s__;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_>>s_>>c__>>s__;
	int sa_,sa__;
	char sc_,sc__;
	sc_=s_[2];
	sa_=(s_[0]-48)*10+(s_[1]-48);
	sc__=s__[2];
	sa__=(s__[0]-48)*10+(s__[1]-48);
	if(sc_=='F'){
		sc_='E';
	}
	if(sc__=='F'){
		sc__='E';
	}
	string ans="";
	if(c_==c__){
		ans+='1';
		if(sa_==sa__){
			ans+='1';
			if((sc_>='A'&&sc_<='C'&&sc__>='A'&&sc__<='C')||(sc_>='D'&&sc_<='E'&&sc__>='D'&&sc__<='E')){
				ans+='1';
				if(abs(sc_-sc__)==1){
					ans+='1';
				}else{
					ans+='0';
				}
			}else{
				ans+="00";
			}
		}else{
			ans+="000";
		}
	}else{
		ans="0000";
	}
	cout<<ans;
	return 0;
}
