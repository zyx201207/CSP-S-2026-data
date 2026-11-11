#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
map<char,int>mp;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	mp['A']=mp['B']=mp['C']=1;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	string s,t;
	s=b[0]+b[1];
	t=d[0]+d[1];
	if(s==t){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(mp[b[2]]==mp[d[2]]){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(mp[b[2]]==0||b[2]=='B'||d[2]=='B'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
