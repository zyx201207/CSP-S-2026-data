#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<char,ll>mp;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	mp['A']=1;
	mp['B']=2;
	mp['C']=3;
	mp['D']=5;
	mp['F']=6;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000\n";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000\n";
		return 0;
	}
	if(!((mp[s1[2]]<=3&&mp[s2[2]]<=3)||(mp[s1[2]]>3&&mp[s2[2]]>3))){
		cout<<"1100\n";
		return 0;
	}
	if(abs(mp[s1[2]]-mp[s2[2]])!=1){
		cout<<"1110\n";
		return 0;
	}
	cout<<"1111\n";
	return 0;
}
