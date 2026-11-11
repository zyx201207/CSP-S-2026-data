#include <bits/stdc++.h>
using namespace std;
int n,a;
string ans;
long long sum;
long long e;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a;
		char c;
		cin>>c;
		string q(a,c);
		ans+=q;
		e+=a;
	}
	for (int i=0;i<e/2;i++)
	{
		if (ans[i]!=ans[ans.size()-1-i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
