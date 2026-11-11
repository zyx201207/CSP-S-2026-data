#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a,ans,maxx=-0x3f3f3f3f;
char s;
string sum;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>s;
		maxx=max(maxx,a);
		for(int i=1;i<=a;i++)
		{
			sum+=s;
		}
	}
	for(int i=sum.size()-1,j=0;i>=0,j<sum.size();i--,j++)
	{
		if(sum[i]==sum[j])
		{
			ans=1;
		}
		else
		{
			ans=0;
		}
	}
	if(ans==1)
	{
		cout<<0;
		return 0;
	}
	if(ans==0)
	{
		cout<<sum.size()-maxx-1;
	}
	return 0;
}
