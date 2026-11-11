#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long n,d,l=0,r,cnt=0;
	string s;
	cin >> n;
	char t;
	for(int i=1;i<=n;i++)
	{
		cin >> d >> t;
		for(int j=1;j<=d;j++)
		{
			s+=t;
		}
	}
	r=s.size();
	while(l<r/2+1)
	{
	    if(s[l]==s[r-l])
		{
			l++;
			r--;
		}
		else
		{
		s[r]=s[l];
		cnt++;
		l++;
		r--;
    	}
	}
	cout << cnt;
	return 0;
}