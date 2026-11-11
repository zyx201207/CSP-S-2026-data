#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int a;
	string b;
	string m;
	bool p=true;
	for(int i=1;i<=n;++i)
	{
		cin>>a>>b;
		for(int j=1;i<=a;++j)
		{
			m+=b;
		}
	}
	if(p)
	{
		int l=1,r=m.size()-1;
		int sum=0;
		while(l<=r)
		{
			if(m[l]!=m[r])
			{
				++sum;
			}
			++l;
			--r;
		}
		cout<<sum;
		return 0;
		}
}
