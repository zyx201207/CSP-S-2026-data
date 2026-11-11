#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string s = "ABCDF";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else if(s1[0] != s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}else if(s1[2] != s[0]&&s1[2]!= s[1]&&s1[2] != s[2]){
		if(s2[2] == s[0]||s2[2] == s[1]||s2[2] == s[2]){
			cout<<"1100";
			return 0;
		}
	}else if(s1[2] != s[3]&&s1[2]!= s[4]){
		if(s2[2] == s[3]||s2[2] == s[4]){
			cout<<"1100";
			return 0;
		}
	}if(s1[2] == s[3] || s1[2] == s[4]){
		cout<<"1111";
		return 0;
	}else if(s1[2] == s[0]||s1[2] == s[2]){
		if(s2[2] == s[0]||s2[2] == s[2]){
			cout<<"1110";
			return 0;
		}
	}else cout<<"1111";
	return 0;
}
