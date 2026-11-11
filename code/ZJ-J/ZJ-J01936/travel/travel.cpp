#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
string c1,c2,s1,s2;
map<char,ll> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['F']=2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(mp[s1[2]]==mp[s2[2]]){
				cout<<1;
				if(abs(s1[2]-s2[2])==1)cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
