//草木逢春，慧如恒沙。神爱世人，妲门永存！！！ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//bool cmp
string s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	
	if(s[0]!=s[7]||s[1]!=s[8])
	{
		cout<<"0000";
		return 0;
	}
	if(s[3]!=s[10]||s[4]!=s[11])
	{
		cout<<"1000";
		return 0;
	}
	if((s[5]<='C')^(s[12]<='C'))
	{
		cout<<"1100";
		return 0;
	}
	if(abs(s[5]-s[12])>1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
