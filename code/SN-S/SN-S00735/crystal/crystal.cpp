#include<bits/stdc++.h> 
using namespace std;
long long m,n;
long long a[500050];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long x=a[n-1],ans=0,left1=n-1,m1=m,left = 0;//max
	long long cnt1=0,cnt2=0;	
	while(x>=a[0]&&left1>=0)
	{
		m1=m;
		cnt1=0;
		cnt2=0;
		for(int i=left1;a[i]==x;i--)
			cnt1++; 
		left = left1-cnt1;
		left1 = left;
		while(m1>0&&left>=0)
		{
			int ll=a[left];
			if(m1>=(x-ll))
			{
				m1-=(x-ll);
				cnt2++;
				left--;
			}
			else
			{
				m1=0;
			}
	}
		x = a[left1];
		ans=max((cnt1+cnt2),ans);
	}
	cout<<ans;
	return 0;
}



