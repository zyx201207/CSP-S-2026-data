#include<bits/stdc++.h>
using namespace std;
int n,a[200005],l,r,cnt;
char s[200005];
string ss;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i] >> s[i];
		for(int j = 0;j < a[i];j++)
		{
			ss += s[i];
		}
	}
	l = 0;
	r = ss.size() - 1;
	while(l <= r)
	{
		if(l >= r)
		{
			cout << cnt;
			return 0;	
		}
		if(ss[l] != ss[r])
		{
			cnt++;
		}
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}
