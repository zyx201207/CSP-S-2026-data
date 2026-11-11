#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N],n;
int sum=0;
char c[N];
int huiwen(string k)
{
	int ans=0;
	for(int i=0,j=sum-1;i<j;i++,j--)
	{
		if(k[i]!=k[j])
		{
			ans++;
		}
	}
	return ans;
}
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
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	string u;
	for(int i=0;i<n;i++)
	{
		u+=c[i+1];
	}
	if(sum>500&&n>2000)
	{	
		cout<<huiwen(u);
	}
	string s;
	for(int i=0;i<sum;i++)
	{
		for(int j=0;j<a[i+1];j++)
		{
			s+=c[i+1];
		}
	}
	cout<<huiwen(s);
	return 0;
}
