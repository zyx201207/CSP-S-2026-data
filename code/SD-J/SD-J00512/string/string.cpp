#include <bits/stdc++.h>
using namespace std;
int hui(string s)
{
	stack<char> st;int ans=0;bool f=1;
	for(int i=0;i<s.size();i++)
	{
		st.push(s[i]);
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(st.top()!=s[i])
		{
			s[i]=st.top();
			ans++;
		}
		st.pop();
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool f=1;
 	string s;
	int n,a[1000000];
	char c[1000000];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	cout<<hui(s);
	return 0;
} 
