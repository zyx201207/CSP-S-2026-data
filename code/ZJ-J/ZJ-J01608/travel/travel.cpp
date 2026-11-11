/*
我去，这题这么水吗
直接全部特判
对的对的
*/
// //freopen() luogu c
// 10min
#include <bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2,s1,s2,tmp,tmp2;
int ans1,ans2,ans3,ans4,tmp1,tmp3;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans1=1;
	else
	{
		cout<<"0000";
		return 0;
	}
	tmp=s1.substr(0,2);
	tmp1=stoi(tmp);
	tmp=s2.substr(0,2);
	tmp3=stoi(tmp);
	ans2=(tmp1==tmp3?1:0);
	if(s1[2]<='C'&&s2[2]<='C'&&s1[2]>='A'&&s2[2]>='A'&&ans2)ans3=1;
	if(s1[2]<='F'&&s2[2]<='F'&&s1[2]>='D'&&s2[2]>='D'&&ans2)ans3=1;
	if(ans3&&abs(s1[2]-s2[2])==1)ans4=1;
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}