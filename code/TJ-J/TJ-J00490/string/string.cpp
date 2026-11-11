#include <bits/stdc++.h>
using namespace std;
int a[10000010];
stack <string> z;
queue <string> sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,ans=0;
	string c;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a >> c;
		for(int j=0;j<a;i++)
		{
			sum.push(c);
			z.push(c);
		}
	}
	while(n--)
	{
		if(z.size()/2<=ans)
		{
			cout << ans << endl;
			return 0;
		}
		else
		{
			for(int i=0;i<z.size();i++)
			{
				if(sum.front()!=z.top())
				{
					ans++;
					
					z.pop();
				}
			}
		}
	}
	return 0;
}
