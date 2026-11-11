#include<bits/stdc++.h>
using namespace std;

string s[10],ans="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++){
		cin>>s[i];
	}
	if(s[1]==s[3]){
		ans+='1';
		if(s[2][0]==s[4][0]&&s[2][1]==s[4][1]){
			ans+='1';
			if((s[2][2]=='A'&&s[4][2]=='B')||(s[2][2]=='A'&&s[4][2]=='C')||(s[2][2]=='B'&&s[4][2]=='A')||(s[2][2]=='B'&&s[4][2]=='C')||(s[2][2]=='C'&&s[4][2]=='B')||(s[2][2]=='C'&&s[4][2]=='A')||(s[2][2]=='D'&&s[4][2]=='F')||(s[2][2]=='F'&&s[4][2]=='D')){
				ans+='1';
				if(((s[2][2]-s[4][2])==1)||((s[4][2]-s[2][2])==1)){
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
		ans+="0000";
	}
	cout<<ans;
	return 0;
}

