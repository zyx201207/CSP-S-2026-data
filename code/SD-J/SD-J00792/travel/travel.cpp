#include<bits/stdc++.h>
#define int long long
#define uint unsigned long long
#define fst ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
using namespace std;
const int N=1e6+5;
string s="",c1,c2,s1,s2;
map<int,char> mp;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	fst;
	cin>>c1>>s1>>c2>>s2;
	mp['A']=1;
	mp['B']=1;
	mp['C']=1;
	mp['D']=2;
	mp['F']=2;
	if(c1==c2) s+="1";
	else{
		s+="0";
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) s+="1";
	else{
		s+="0";
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&mp[s1[2]]==mp[s2[2]]) s+="1";
	else{
		s+="0";
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&mp[s1[2]]==mp[s2[2]]){
		char a1=s1[2],a2=s2[2];
		if(a1=='A'&&a2=='B'||a1=='B'&&a2=='A'||a1=='B'&&a2=='C'||a1=='C'&&a2=='B'||a1=='D'&&a2=='F'||a1=='F'&&a2=='D'){
			s+="1";
		}
		else{
			s+="0";
		}
	}
	else{
		s+="0";
	}
	cout<<s;
	return 0;
}
