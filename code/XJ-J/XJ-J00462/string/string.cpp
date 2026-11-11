#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long l1[200005];
long long l2[200005];
long long r1[200005];
long long r2[200005];
long long cnt1=1;
long long cnt2=1;
long long sum,t;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for(int i=1;i<=n/2;i++)
	{
		l1[i]=cnt1;
		l2[i]=cnt2;
		cnt1+=a[i];
		cnt2+=a[n-1];
		r1[i]=cnt1;
		r2[i]=cnt2;
	}
	for(int i=1;i<=n/2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(r1[i]>=l2[j]&&l1[i]<=l2[j]&&r1[i]>=r2[j])
			{
				if(c[i]==c[n-j])
				{
					t+=r1[i]-l2[j]+1;
				}
			}
			else
			{
				break;
			}
		}
	}
	cout<<sum-t;
	return 0;
}