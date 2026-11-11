#include <bits/stdc++.h>
using namespace std;
struct hui{
	long long len;
	char a;
}s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=1,r=n;
	long long cnt=0,tot=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].len;
		cin>>s[i].a;
	}
	while(l<r)
	{
		long long x=s[l].len;
		char c1=s[l].a;
		l++;
		while(x>0)
		{
			char c2=s[r].a;
			if(s[r].len<=x)
			{
				x-=s[r].len;
				if(c1!=c2) cnt+=s[r].len;
				s[r].len=0;
				r--;
			}
			else 
			{
				s[r].len-=x;
				if(c1!=c2)cnt+=x;
				x=0;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}