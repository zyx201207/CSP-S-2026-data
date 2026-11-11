#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	if((s1[2]=='F' and s2[2]=='D') or (s1[2]=='D' and s2[2]=='F')){
		cout<<"1111";
		return 0;
	}
	if((s1[2]=='A' and s2[2]=='C') or (s1[2]=='C' and s2[2]=='A')){
		cout<<"1110";
		return 0;
	}
	if((s1[2]=='A' and s2[2]=='B') or (s1[2]=='B' and s2[2]=='A') or (s1[2]=='B' and s2[2]=='C') or (s1[2]=='C' and s2[2]=='B')){
		cout<<"1111";
		return 0;
	}
	cout<<"1100";
	return 0;
}
