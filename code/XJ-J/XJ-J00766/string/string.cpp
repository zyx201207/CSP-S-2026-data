#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,k;
ll a[2010];
void o(int j)
{
	for(int i=1;i<=j;i++)
	{
		s+=k;
	}
	return ;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>k;
		o(a[i]);
		sum+=a[i];
	}
		int cnt=0,cnt2=0;
		for(int i=0;i<sum/2;i++)
		{
			if(s[i]!=s[sum-i-1])
			{
				cnt++;
			}
		}
		for(int i=0;i<sum/2;i++)
		{
			if(s[sum-i-1]!=s[i])
			{
				cnt2++;
			}
		}
		cout<<min(cnt,cnt2);
}