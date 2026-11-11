#include<bits/stdc++.h>
using namespace std;
map<char,bool> mp[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp[0]['A']=1,mp[0]['B']=1,mp[0]['C']=1;
	mp[1]['E']=1,mp[1]['F']=1;
	string  c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0000",exit(0);
	if(s1.substr(0,2)==s2.substr(0,2)) cout<<"1";
	else cout<<"000",exit(0);
	if(mp[0][s1[2]]&&mp[0][s2[2]]||mp[1][s1[2]]&&mp[1][s2[2]]) cout<<"1";
	else cout<<"00",exit(0);
	if(abs((int)s1[2]-s2[2])==1) cout<<"1";
	else cout<<"0";
	return 0; 
}
