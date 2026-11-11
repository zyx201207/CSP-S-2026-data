#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s1="",s;
	for(int i = 1; i<=n; i++)
	{
		int l;
		cin>>l;
		string c;
		cin>>c;
		long long slen=c.size()*l;
		//cout<<slen;
		while(c.size()<slen)
		{
			c+=c;
		}
		c=c.substr(0,slen);
		//cout<<c<<endl;
		s1+=c;
		//拼接 
	}
	long long ans=0;
	long long slen=s1.size();
	for(int i = 0; i<=slen/2-1; i++)//循环到左边最后一个 
	{
			if((s1[i]-'0')!=(s1[slen-1-i]-'0'))//如果对称数不同答案就加一 
			{
				ans++;
			}
	}
	cout<<ans;
	return 0;
 } 
