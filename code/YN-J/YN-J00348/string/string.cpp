#include <bits/stdc++.h>
using namespace std;
long long n,a;
long long sum,l,r,cnt;
string s,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a >> c;
		sum+=a;
		for(long long j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	bool flag=1;
	for(int i=0;i<sum/2;i++)
	{
		if(s[i]!=s[sum-i-1])
		{
			flag=0;
			break;
		}
	}
	l=0,r=sum-1;
	if(!flag)
	{
		while(l<=r)
		{
			if(s[l]!=s[r])
			{
				cnt++;
			}
			l++,r--;
		}
	}
	cout << cnt;
    return 0;
}
