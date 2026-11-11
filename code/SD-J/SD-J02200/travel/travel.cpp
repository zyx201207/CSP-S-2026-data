#include<bits/stdc++.h>
using namespace std;
bool same_as(char a,char b){
	if (a=='A' && b<='C') return true;
	if (a=='B' && (b=='A' || b=='C')) return true;
	if (a=='C' && (b=='A' || b=='B')) return true;
	if (a=='D' && b=='F') return true;
	if (a=='F' && b=='D') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_1,s_1,c_2,s_2;cin>>c_1>>s_1>>c_2>>s_2;
	cout<<(c_1==c_2)<<(c_1==c_2 && s_1[0]==s_2[0] && s_1[1]==s_2[1])<<(c_1==c_2 && s_1[0]==s_2[0] && s_1[1]==s_2[1] && same_as(s_1[2],s_2[2]));
	cout<<(c_1==c_2 && s_1[0]==s_2[0] && s_1[1]==s_2[1] && same_as(s_1[2],s_2[2]) && abs(s_1[2]-s_2[2])==1);
	return 0;
}

