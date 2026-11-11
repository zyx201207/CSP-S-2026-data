#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
map<char,int>mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	mp['A']=1,mp['B']=2,mp['C']=3,mp['D']=4,mp['F']=5;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(s1[2]>'C'&&s2[2]>'C'||s1[2]<='C'&&s2[2]<='C'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(mp[s1[2]]-mp[s2[2]])==1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
