#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt=0;
	cin>>n;
	string c,s;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		for(int i=0;i<a;i++) s+=c;
	}
	for(int i=0;i<=s.size()/2-1;i++)
	{
		if(s[i]!=s[s.size()-1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
} 

