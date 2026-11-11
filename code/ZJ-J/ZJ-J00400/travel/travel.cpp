#include<bits/stdc++.h>
using namespace std;
string che1,che2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>che1>>s1>>che2>>s2;
	if(che1!=che2) cout<<"0000";
	else{
		if(s1[0]!=s2[0]||s1[1]!=s2[1]) cout<<"1000";
		else{
			if((s1[2]<='C'&&s2[2]>'C')||(s1[2]>'C'&&s2[2]>='C')) cout<<"1100";
			else{
				if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')) cout<<"1110";
				else cout<<"1111";
			}
		}
	}
	return 0;
}
