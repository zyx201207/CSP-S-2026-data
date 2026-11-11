#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s1,s2,c1,c2,ans="0000";
int k1=0,k2=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans[0]='1';
	else{
		cout<<ans;
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2)) ans[1]='1';
	else{
		cout<<ans;
		return 0;
	}
	if(s1.back()=='D'||s1.back()=='F') k1=1;
	if(s2.back()=='D'||s2.back()=='F') k2=1;
	if(k1==k2) ans[2]='1';
	else{
		cout<<ans;
		return 0;
	}
	if(k1==1){
		if((s1.back()=='D'&&s2.back()=='F')||(s1.back()=='F'&&s2.back()=='D')) ans[3]='1';
	}else{
		if((s1.back()=='A'&&s2.back()=='B')||(s1.back()=='B'&&s2.back()=='A')||(s1.back()=='B'&&s2.back()=='C')||(s1.back()=='C'&&s2.back()=='b')) ans[3]='1';
	}
	cout<<ans;
	return 0;
}

