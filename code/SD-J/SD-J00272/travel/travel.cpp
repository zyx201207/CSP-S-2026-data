#include<bits/stdc++.h>//Trick||Treat!
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans;
	if(c1==c2)ans.push_back('1');
	else ans.push_back('0');
	string d = s1.substr(0,2);
	string b = s2.substr(0,2);
	if(ans[0]=='1'&&b==d)ans.push_back('1');
	else ans.push_back('0');
	if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))ans.push_back('0');
	else if(ans[1]=='0') ans.push_back('0');
	else ans.push_back('1');
	if(ans[2]=='1'&&abs(s1[2]-s2[2])==1)ans.push_back('1');
	else ans.push_back('0');
	cout<<ans;
	return 0;
}
