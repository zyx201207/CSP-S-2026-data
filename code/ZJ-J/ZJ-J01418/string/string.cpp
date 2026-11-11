//草木逢春，慧如恒沙。神爱世人，妲门永存！！！ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
//bool cmp

string s;
int n,ans;

/*char find(int x)
{
	//根据下标找字母 
}*/

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=0;i<n;i++)
	{
		int cnt;char c;
		cin>>cnt>>c;
		//scanf("%d",&cnt);scanf("%s",&c);cout<<cnt<<c;
		for(int j=0;j<cnt;j++)
		{
			s.push_back(c);
		}
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
