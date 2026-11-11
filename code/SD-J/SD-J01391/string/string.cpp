#include<bits/stdc++.h>
using namespace std;
const int N=200100;
long long a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long sum=0,ans=0;
	vector<char> s1,s2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long p1=a[1],p2=a[n],L=0;
	if(sum%2==0)
	{
		L=sum/2;
		for(long long i=1,j=1;i<=sum/2;i++)
		{
			if(i<=p1)
				s1.push_back(c[j]);
			else j++,p1+=a[j],s1.push_back(c[j]);
		}
		for(long long i=sum,j=n;i>sum/2;i--)
		{
			long long size=sum-i+1;
			if(size<=p2)
				s2.push_back(c[j]);
			else j--,p2+=a[j],s2.push_back(c[j]);
		}	
	}
	else
	{
		L=sum/2+1;
		for(long long i=1,j=1;i<=sum/2+1;i++)
		{
			if(i<=p1)
				s1.push_back(c[j]);
			else j++,p1+=a[j],s1.push_back(c[j]);
		}
		for(long long i=sum,j=n;i>sum/2;i--)
		{
			long long size=sum-i+1;
			if(size<=p2)
				s2.push_back(c[j]);
			else j--,p2+=a[j],s2.push_back(c[j]);
		}
	}
	for(long long i=0;i<L;i++)
	{
		if(s1[i]!=s2[i]) ans++;
	}
	cout<<ans;
	return 0;
}
