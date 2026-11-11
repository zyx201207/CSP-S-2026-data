#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("traval.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]<=67 && s2[2]<=67 || 67<s1[2]&&s1[2]<=70 && 67<s2[2]&&s2[2]<=70) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(s1[2]+1==s2[2] || s1[0]-1==s2[2] || s1[2]==68 && s1[2]==70 || s1[2]==70 && s1[2]==68) cout<<"1";
	else cout<<"0";
	return 0;
}
