#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string q;
	int cnt=0;
	cin >> n;
	if(n==1)
	{
		cout << 0;
		return 0;
	}
	if(n==2)
	{
		int a,b;
		char c,d;
		cin >> a >> c;
		cin >> b >> d;
		if(c==d)
		{
			cout << 0;
		}
		else
		{
			cout << min(a,b);
		}
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		char s;
		cin >> s;
		for(int j=0;j<a;j++)
		{
			q[j]=s;
		}
	}
	int l=q.size();
	for(int i=0;i<l;i++)
	{
		if(q[i]!=q[l+i-1])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
