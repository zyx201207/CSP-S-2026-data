#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2; 
	bool b=false;
	if(c1==c2){
		cout<<1;
		b=true;
	}
	else cout<<0;
	if(s1[0]==s2[0] && s1[1]==s2[1] && b){
		cout<<1;
	}
	else{
		b=false;
		cout<<0;
	}
	mp[s1[2]]++;
	mp[s2[2]]++;
	if(((mp['A'] && mp['B']) || (mp['A'] && mp['C']) || (mp['B'] && mp['C']) || (mp['D'] && mp['F'])) && b) cout<<1;
	else{
		cout<<0;
		b=false;	
	}
	if(((mp['A'] && mp['B']) || (mp['B'] && mp['C']) || (mp['D'] && mp['F'])) && b) cout<<1;
	else cout<<0;
}
