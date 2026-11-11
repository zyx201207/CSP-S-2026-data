#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
map<char,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int t1=(s2[0]-'0')*10+s2[1]-'0',t2=(s4[0]-'0')*10+s4[1]-'0';
	if(t1==t2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	mp['A']=1; mp['B']=1; mp['C']=1;
	mp['D']=0; mp['E']=0;
	if(mp[s2[2]]==mp[s4[2]]) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s2[2]-s4[2])==1) cout<<1;
	else cout<<0;
	return 0;
}
