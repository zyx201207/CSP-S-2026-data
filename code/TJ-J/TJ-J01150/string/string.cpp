#include <bits/stdc++.h>
using namespace std;
long long n,ans=0,l,r,num,lt;
string s1;
string s[200001];
int snum[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> num >> s1;
		s[i]=s1;
		snum[i]=num;
	}
	r=n-1;
	l=0;
	if (n%2!=0)
	{
		n=(n+1)/2;
		ans+=1;
	}
	else
	{
		n/=2;
	}
	for (int i=0;i<n;i++)
	{
//		if (s[l]==s[r])
//		{
//			ans+=min(sum[l],sum[r]);
//			lt=abs(snum[l]-snum[r]);
//		}
		//else
		//{
		if (s[l]!=s[r])
		{
			ans+=min(snum[l],snum[r]);
		}
		//lt=max(snum[l],snum[r]);
		//}
		//lt--;
		if (min(snum[l],snum[r])==snum[l])
		{
			l++;
			snum[r]-=snum[l];
			if (snum[r]<=0)
			{
				r--;
			}
		}
		else
		{
			r--;
			snum[l]-=snum[r];
			if (snum[l]<=0)
			{
				l++;
			}
		}
	}
	cout << ans;
	return 0;
}
