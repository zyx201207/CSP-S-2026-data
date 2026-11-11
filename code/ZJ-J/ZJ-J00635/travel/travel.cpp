#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+='1';
		if(s1.substr(0,2)==s2.substr(0,2)){
			ans+='1';
			bool f1,f2;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') f1=0;
			else f1=1;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') f2=0;
			else f2=1;
			if(f1==f2){
				ans+='1';
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) ans+='1';
				else ans+='0';
			}
			else ans+="00";
		}
		else ans+="000";
	}
	else ans+="0000";
	cout<<ans;
	return 0;
}
