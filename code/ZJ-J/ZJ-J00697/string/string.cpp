#include<bits/stdc++.h>
using namespace std;
int n,a[200001],l=1,r;
long long sum;
char s[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	r=n;
	while(l<=r)
	{
		if(l==r)
		{
			if(s[l]!=s[r]) sum+=(a[l]/2);
			break;
		}
		if(s[l]==s[r])
		{
			if(a[l]>a[r]) a[l]-=a[r],r--;
			else if(a[l]==a[r]) l++,r--;
			else a[r]-=a[l],l++;
		}
		else 
		{
			if(a[l]>a[r]) a[l]-=a[r],sum+=a[r],r--;
			else if(a[l]==a[r]) l++,sum+=a[r],r--;
			else a[r]-=a[l],sum+=a[l],l++;
		}
	}
	cout<<sum;
	return 0;
}