#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0; cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		int a; cin>>a;
		char s1; cin>>s1;
		for(int j=0;j<a;j++)
		{
			s+=s1;
		}
	}
	int l;
	l=s.size();

	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	
	return 0;
}

