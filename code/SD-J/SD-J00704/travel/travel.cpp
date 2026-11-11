#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
string s1,s2,s3,s4,ans=""; 
bool check(char x,char y){
	return (x>='A'&& x<='C' && y>='A'&& y<='C') || (x>='D'&& x<='F' && y>='D'&& y<='F');
}
bool check2(char x,char y){
	return (x=='A' && y=='B') || (x=='B' && y=='C') || (x=='D' && y=='F') || (x=='B' && y=='A') || (x=='C' && y=='B') || (x=='F' && y=='D');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		ans+="1";
		string st1="",st2="";
		st1+=s2[0];st2+=s4[0];
		st1+=s2[1];st2+=s4[1];
		if(st1==st2){
			ans+="1";
			if(check(s2[2],s4[2])){
				ans+="1";
				if(check2(s2[2],s4[2])){
					ans+="1";
				}
				else ans+="0";
			}
			else ans+="00";
		}
		else ans+="000"; 
	}
	else ans="0000";
	cout<<ans<<endl;
	return 0;
}

