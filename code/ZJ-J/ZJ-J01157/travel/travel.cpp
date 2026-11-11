#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,s5,s6;
char c1,c2;
map<char,int>mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	c1=s2[2],c2=s4[2];
	s5=s2.substr(0,2),s6=s4.substr(0,2);
	mp['A']=1,mp['B']=2,mp['C']=3,mp['D']=4,mp['F']=5;
	cout<<(s1==s3?'1':'0');
	cout<<((s1==s3&&s5==s6)?'1':'0');
	cout<<((s1==s3&&s5==s6&&((mp[c1]<4&&mp[c2]<4)||(mp[c1]>3&&mp[c2]>3)))?'1':'0');
	cout<<((s1==s3&&s5==s6&&abs(mp[c1]-mp[c2])==1&&mp[c1]+mp[c2]!=7)?'1':'0');
	return 0;
}
