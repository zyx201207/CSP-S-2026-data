#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct str{
	int num;
	char c;	
}s[N];
int sum;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n; cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf ("%lld",&s[i].num);
		cin>>s[i].c;
	}
	int l=1,r=n;
	while (l<=r)
	{
		int id;
		if (s[l].num<=s[r].num)
		{
			id=l;
		}
		else id=r;
		if (s[l].c!=s[r].c)
		{
			sum+=s[id].num;
		}
		if (id==l) s[r].num-=s[l++].num;
		else s[l].num-=s[r--].num;
	}
	cout<<sum;
	
	return 0;
} 

