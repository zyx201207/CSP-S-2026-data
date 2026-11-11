#include<bits/stdc++.h>
using namespace std;
void solve(){
	string n,s,nn,ss;
	cin>>n>>s>>nn>>ss;
	string ans=" ";
	ans+=((n==nn)?'1':'0');
	ans+=((ans[1]=='1'&&s.substr(0,2)==ss.substr(0,2))?'1':'0');
	vector<int>num(300,0);
	num[(int)('A')]=1;
	num[(int)('B')]=1;
	num[(int)('C')]=1;
	num[(int)('D')]=2;
	num[(int)('F')]=2;
	
	vector<int>l(300,0);
	l[(int)('A')]=1;
	l[(int)('B')]=2;
	l[(int)('C')]=3;
	l[(int)('D')]=5;
	l[(int)('F')]=6;
	int k=num[s[2]],kk=num[ss[2]];
	ans+=((ans[2]=='1'&&k==kk)?'1':'0');
	ans+=((ans[3]=='1'&&abs(l[s[2]]-l[ss[2]])==1)?'1':'0');
	cout<<ans.substr(1);
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
}
