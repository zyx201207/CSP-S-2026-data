#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n =0;
	cin>> n;
	string s;
	for(int i =0;i<n;i++)
	{
		int a;
		char b;
		cin>>a>>b;
		for(int i =0;i<a;i++)
			s+=b;
	}
	int cnt = 0;
	for(int i =0,j = s.size()-1;i<s.size()/2;i++,j--)
	{
		if(s[i]!=s[j])
		{
			cnt++;
			s[j]=s[i];
		}
	}
	cout << cnt;
	return 0;
}
