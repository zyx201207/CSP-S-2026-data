#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	long long m=0,ans=0;
	cin>>a[0]>>c[0];
	m+=a[0];
	for(int i=1;i<n;i++)
	{
		cin>>a[i]>>c[i];
		m+=a[i];
		if(c[i]==c[i-1])
		{
			a[i-1]+=a[i];
			i--;
			n--;
		}
	}
	int l=0,r=n-1;
	while(l<r)
	{
		if(a[l]==a[r])
		{
			if(c[l]!=c[r])ans+=a[l];
			l++;
			r--;
			continue;
		}
		if(a[l]>a[r])
		{
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r];
			r--;
			continue;
		}
		if(a[l]<a[r])
		{
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];
			l++;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
