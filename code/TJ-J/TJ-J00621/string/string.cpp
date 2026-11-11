#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		string p;
		cin>>p;
		for(int j=1;j<=a;j++)
		{
			s+=p;
		}
	} 
	int cnt=0;
	int l=0,r=s.size()-1;
	while(l<=r)
	{
		
		if(s[l]!=s[r]) 
		{
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

