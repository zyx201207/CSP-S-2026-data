#include <bits/stdc++.h>
using namespace std;
int n,a,ans;
char c;
vector<char> f;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			f.push_back(c);
	}
	for(int i=0;i<f.size()/2;i++)
	{
		if(f[i]!=f[f.size()-1-i])
			ans++;
	}
	cout<<ans;
	return 0;
}
