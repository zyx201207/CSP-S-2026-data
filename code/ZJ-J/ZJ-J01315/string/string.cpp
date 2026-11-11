#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l;
struct point
{
	int x;
	char c;
}a[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
		l+=a[i].x;
	}
	int c1=1,c2=n,s1=a[1].x,s2=a[n].x,s3=0,s4=0;
	while(s3<l)
	{
		if(a[c1].c!=a[c2].c)
		{
			s4+=(min(s1,s2)-s3);
		}
		s3=min(s1,s2);
		if(s1==s2)
		{
			c1++,c2--;
			s1+=a[c1].x;
			s2+=a[c2].x;
		}
		else if(s1<s2)
		{
			c1++;
			s1+=a[c1].x;
		}
		else if(s1>s2)
		{
			c2--;
			s2+=a[c2].x;
		}
	}
	cout<<s4/2;
	return 0;
}
