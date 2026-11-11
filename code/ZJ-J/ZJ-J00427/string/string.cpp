#include <bits/stdc++.h>
using namespace std;
int n,sum=0,q[200005];
string s,e[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i]>>e[i];
		for(int j = sum;j<sum+q[i];j++)
		{
			s+= e[i];
		}
		sum += q[i];
	}

	/*
	for(int i=1;i<=n;i++)
	{
		for(int j = sum;j<sum+q[i];j++)
		{
			s+= e[i];
		}
		sum += q[i];
	}
	*/

	int l=0,r = sum-1,ans = 0;
	while(r>l)
	{
		if(s[l] != s[r])
		{
			ans += 1;
		}
		l+=1;
		r-=1;
	}

	cout<<ans;
	return 0;
}

