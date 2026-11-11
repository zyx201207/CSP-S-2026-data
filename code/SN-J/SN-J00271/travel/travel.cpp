#include <bits/stdc++.h>
using namespace std;
bool istp(string a,string b){
	char m=a[2];
	char n=b[2];
	if((m=='A' && (n=='B' || n=='C')) || (m=='B' && (n=='A' || n=='C')) || (m=='C' && (n=='A ' || n=='B')) || (m=='D' && n=='E') || (m=='E' && n=='D'))
	return true;
	else return false;
}
int main(){
	string c1,s1,c2,s2;
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	if(c1==c2) cout<<1;
	else cout<<0;
	
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]) cout<<1;
	else cout<<0;
	
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && istp(s1,s2)) cout<<1;
	else cout<<0;
	
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && istp(s1,s2) && (s1[2]==s2[2]+1 || s1[2]==s2[2]-1)) cout<<1;
	else cout<<0;
	
	return 0;
} 

