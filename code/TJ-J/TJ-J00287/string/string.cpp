#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s1="";
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int t;
		string s;
		cin >> t >> s;
		for(int j=0;j<t;j++)s1+=s;
	}
	string s2=s1;
	reverse(s2.begin(),s2.end());
	if(s1==s2)
	{
		cout << 0;
		return 0;
	}
	string a1,a2;
	for(int i=0;i<s1.size()/2;i++)
	{
		a1+=s1[i];
	}
	for(int i=0;i<s2.size()/2;i++)
	{
		a2+=s2[i];
	}
	for(int i=0;i<s1.size()/2;i++)
	{
		if(a1[i]!=a2[i])cnt++;
	}
	cout << cnt;
	return 0;
} 
