#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],k,ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		string y;
		cin>>x>>y;
		if(s[k]==y[0])a[k]+=x;
		else
		{
			k++;
			a[k]=x;
			s[k]=y[0];
		}
	}
	long long x=(k+1)/2;
	for(int i=1;i<=x;i++)
	{
		int j=k-x+1;
		if(s[i]==s[j])ans+=max(a[i],a[j])-min(a[i],a[j]);
		else ans+=min(a[i],a[j]);
	}
	cout<<ans;
}
