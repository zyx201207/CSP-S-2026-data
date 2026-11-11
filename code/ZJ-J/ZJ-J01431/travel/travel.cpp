#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ck(char a,char b){
	if(a=='D' || a=='F')
	if(b=='D' || b=='F') return true;
	if(a=='A' || a=='B' || a=='C')
	if(b=='A' || b=='B' || b=='C') return true;
	return false;
}
bool ck2(char a,char b){
	if(a=='A' && b=='C') return false;
	if(a=='C' && b=='A') return false;
	return true;
}
int main()
{
 freopen("travel.in","r",stdin);
 freopen("travel.out","w",stdout);
 cin>>c1>>s1>>c2>>s2;
 if(c1==c2) {
 	cout<<1;
 	if(s1[0]==s2[0] && s1[1]==s2[1]){
 		cout<<1;
 		if(ck(s1[2],s2[2])){
 			cout<<1;
 			if(ck2(s1[2],s2[2])) cout<<1;
 			else cout<<0;
		}
		else cout<<"00";
	}
	else cout<<"000";
 }
 else cout<<"0000";
 return 0;
 //AKOI
}

