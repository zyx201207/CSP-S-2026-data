#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1>>s1>>c2>>s2;
	string ans="";
	if(c1==c2){
		ans+="1";
		if(s1[1]==s2[1]){
			ans+="1";
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				ans+="1";
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')){
					ans+="1";
				}else{
					ans+="0";
				}
			}else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				ans+="1";
				if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					ans+="1";
				}else{
					ans+="0";
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
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}