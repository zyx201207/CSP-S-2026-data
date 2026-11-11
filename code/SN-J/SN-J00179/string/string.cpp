#include<bits/stdc++.h>
using namespace std;
int n;
long long a,x;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a;
		cin >> c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long l=0,r=s.size()-1;
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			x++;
		}
		l++;
		r--;
	}
	cout << x;
	return 0;
}
