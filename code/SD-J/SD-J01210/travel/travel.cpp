#include<bits/stdc++.h>
using namespace std;
int gd[5] = {0,0,0,1,1};
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if((s1[0] == s2[0]) && (s1[1] == s2[1])) cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if(gd[s1[2] - 'A'] == gd[s2[2]-'A']) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2] - s2[2]) == 1) cout<<1;
	else cout<<"0";
	return 0;
} 
