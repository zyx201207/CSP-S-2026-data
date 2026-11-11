#include <bits/stdc++.h>
using namespace std;
long long n, cnt=0, a, len;

struct Sub
{
	long long ed;
	char c;
}s[200005];


int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	long long mn=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>s[i].c;
		len+=a;
		s[i].ed=len;
		mn=min(a, mn);
	}
	for(long long i=0;i<=len/2 && i<len-i-1;i+=mn)
	{
		char t1, t2;
		long long k=len-i-1;
		for(int j=1;j<=n;j++)
		{
			if(i<s[j].ed)
			{
				t1=s[j].c;
				break;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(k<s[j].ed)
			{
				t2=s[j].c;
				break;
			}
		}
		if(t1!=t2)
		{
			cnt+=mn;
		}
//		cout<<i<<" "<<t1<<" "<<k<<" "<<t2<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}
