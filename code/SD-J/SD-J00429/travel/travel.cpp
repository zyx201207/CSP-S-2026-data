#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	map<char,int> mp,m;
	mp['A']=1;mp['B']=1,mp['C']=1,mp['D']=2,mp['F']=2;
	m['A']=1;m['B']=2,m['C']=3,m['D']=4,m['F']=5;
	string la,sa,lb,sb;cin>>la>>sa>>lb>>sb;
	if (la!=lb) cout<<"0000";
	else if (sa[0]+sa[1]!=sb[0]+sb[1]) cout<<"1000";
	else if (mp[sa[2]]!=mp[sb[2]]) cout<<"1100";
	else if (abs(m[sa[2]]-m[sb[2]])!=1) cout<<"1110";
	else cout<<"1111";
	return 0;
}

