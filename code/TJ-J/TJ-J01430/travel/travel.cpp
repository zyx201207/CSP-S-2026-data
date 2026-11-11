#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
unordered_map<char,bool> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string sc,s,scx,sx;
	cin>>sc>>s>>scx>>sx;
	int c=stoi(sc),cx=stoi(scx);
	if(c!=cx){
		cout<<"0000";
		return 0;
	}if(!(s[0]==sx[0]&&s[1]==sx[1])){
		cout<<"1000";
		return 0;
	}
	mp['A']=true;
	mp['B']=true;
	mp['C']=true;
	mp['D']=false;
	mp['F']=false;
	if(mp[s[2]]!=mp[sx[2]]){
		cout<<"1100";
		return 0;
	}if( !mp[s[2]] || (s[2]=='B'||sx[2]=='B') ){
		cout<<"1111";
	}else cout<<"1110";
	return 0;
}
