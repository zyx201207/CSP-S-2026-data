#include<iostream>
#include<cstring>
using namespace std;
string ans;
bool f1(string s1,string s2){
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		return true;
	}
	return false;
}
bool f2(string s1,string s2){
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		ans+="0000";
	}
	else{
		ans+="1";
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			ans+="1";
			if(f1(s2,s4)==true){
				ans+="1";
				if(s2[0]==s4[0]&&s2[1]==s4[1]&&f2(s2,s4)==true){
					ans+="1";
				}
				else{
					ans+="0";
				}
			}
			else{
				ans+="00";
			}
		}
		else{
			ans+="000";
		}
	}
	cout<<ans;
	return 0;
}
