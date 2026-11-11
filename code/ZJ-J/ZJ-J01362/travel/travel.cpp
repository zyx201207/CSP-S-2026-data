#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	if(s==s2){
		if(s1.substr(0,2)==s3.substr(0,2)){
			if((s1[2]-'A'<=2 && s3[2]-'A'<=2)||(s1[2]-'A'>2 && s3[2]-'A'>2)){
				if(abs((s1[2]-s3[2])==1)||((s1[2]=='F'&&s3[2]=='D')||(s1[2]=='D'&&s3[2]=='F')))ans+="1111";
				else{
					ans+="1110";
				}
			}
			else{
				ans+="1100";
			}
		}
		else ans+="1000";
	}
	else {
		ans+="0000";
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
