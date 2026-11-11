#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
map<char,int> m;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	m['A']=m['B']=m['C']=0;
	m['D']=m['F']=1;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if (s1.substr(0,2)==s2.substr(0,2))
		cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if (m[s1[2]]==m[s2[2]]) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if (m[s1[2]]==1) cout<<"1";
	else if (s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
		cout<<"1";
	else cout<<"0";
	return 0;
}
