#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
bool check(char c){
	if(c=='A'||c=='B'||c=='C')return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1])cout<<"0000";
	else{
		cout<<1;
		if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"000";
		else{
			cout<<1;
			if(check(s1[2])!=check(s2[2]))cout<<"00";
			else{
				cout<<1;
				if(check(s1[2])&&abs(s1[2]-s2[2])!=1)cout<<0;
				else cout<<1;
			}
		}
	}
	return 0;
} 
