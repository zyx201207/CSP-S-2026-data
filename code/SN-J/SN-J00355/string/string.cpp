#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a[200005];
	char c[200005];
	int ans=0;
	string s_;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s_+=c[i];
		}
	}
	string s=s_;
	reverse(s_.begin(),s_.end());
	if(s==s_) cout<<ans;
	else
	{
		for(int i=0;i<=s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-1-i])
			{
				s[s.size()-1-i]=s[i];
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
 } 
