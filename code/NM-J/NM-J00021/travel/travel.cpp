#include <bits/stdc++.h>
using namespace std;
bool check(char a,char b){
	if(a==b) return true;
	else if(a!='F'&&a!='D'&&b!='F'&&b!='D')	return true;
	else if((a=='F'||a=='D')&&(b=='F'&&b=='D')) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]) {//同一节车厢
	    return cout<<"0000",0;	
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]) return cout<<"1000",0;//同一排
	if(check(s1[2],s2[2])) {//过道同一侧
		if(s1[2]=='A'&&s2[2]=='B') return cout<<"1111",0; 
		if(s1[2]=='B'&&((s2[2]=='A')&&s2[2]=='C')) return cout<<"1111",0; 
		if(s1[2]=='F'&&s2[2]=='D') return cout<<"1111",0; 
		if(s1[2]=='D'&&s2[2]=='F') return cout<<"1111",0;
		cout<<"1110"; 
	}
	else cout<<"1100";
	return 0;
}
