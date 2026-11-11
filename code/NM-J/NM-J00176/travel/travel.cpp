#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+="1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	bool flag1=s1[0]==s2[0]&&s1[1]==s2[1];
	if(flag1){
		ans += "1";
	}
	else{
		ans+="0";
	} 

	bool flag2=(s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>2&&s2[2]-'A'>2);
	if(flag1&&flag2){
		ans+="1";
	}
	else{
		ans+="0";
	}

	if(flag1&&flag2&&(abs(s1[2]-s2[2])==1)){
		ans+="1";
	}
	else {
		ans+="0";
	}

	cout<<ans;
	return 0;
}