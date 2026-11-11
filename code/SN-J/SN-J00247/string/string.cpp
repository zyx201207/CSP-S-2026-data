#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	while(n--)
	{
		int num;
		string zi;
		cin>>num>>zi;
		for(int i=1;i<=num;i++)
		{
			s+=zi;
		}
	}
	ll len=s.size(),ans=0;
	ll l=len/2,r=len/2+1;
	if(len%2!=0)r++;
	l-=1;
	r-=1;
	for(ll i=l,j=r;i>=0,j<len;i--,j++)
	{
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
