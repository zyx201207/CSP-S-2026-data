#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)cout<<"0000";
	else{
		if(s2.substr(0,2)!=s4.substr(0,2))cout<<"1000";
		else{
			if('A'<=s2[2]&&s2[2]<='C'&&'D'<=s4[2]&&s4[2]<='F'||
			   'D'<=s2[2]&&s2[2]<='F'&&'A'<=s4[2]&&s4[2]<='C')cout<<"1100";
			else{
			   	if(s2[2]=='A'&&s4[2]=='B'||
				   s2[2]=='B'&&(s4[2]=='A'||s4[2]=='C')||
				   s2[2]=='C'&&s4[2]=='B'||
				   s2[2]=='D'&&s4[2]=='F'||
				   s2[2]=='F'&&s4[2]=='D')cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return 0;
}
