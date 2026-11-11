#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
vector<long long> v;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	long long maxx=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx*n<=1e7)
	{
		string s="";
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s+=c[i];
			}
		}
		for(int i=0;i<s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-i-1])
			{
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
	}
	v.push_back(0);
	for(int i=1,j=n;i<=j;)
	{
		if(a[i]<=a[n]-a[j-1])
		{
			v.push_back(a[i]);
			i++;
		}
		else
		{
			v.push_back(a[n]-a[j-1]);
			j--;
		}
	}
	for(int i=1;i<v.size();i++)
	{
		int x=lower_bound(a+1,a+n+1,v[i])-a;
		int y=upper_bound(a+1,a+n+1,a[n]-v[i])-a;
		if(c[x]!=c[y])
		{
			sum+=v[i]-v[i-1];
		}
	}
	cout<<sum;
	return 0;
}
