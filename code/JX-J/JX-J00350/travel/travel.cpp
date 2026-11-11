#include<bits/stdc++.h>
using namespace std;
int l1,l2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>l1>>s1>>l2>>s2;
	if(l1==l2){
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			if((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C') )||  ((s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')))||
			((s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B')))|| ( s1[2]=='D'&&s2[2]=='F'  ) ||( s1[2]=='F'&&s2[2]=='D')){
				if(   (s1[2]=='A'&&s2[2]=='B' )|   (s1[2]=='B'&&s2[2]=='C')|| (  s1[2]=='D'&&s2[2]=='F' )||
					(s1[2]=='B'&&s2[2]=='A' )||   (s1[2]=='C'&&s2[2]=='B' )|| (  s1[2]=='F'&&s2[2]=='D' )) cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}
		else cout<<"1000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
