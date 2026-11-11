#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],p;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	if(n==1&&m==0){
		cout<<1;
		return 0;
	}
	for(int i=2;i<=n;i++)if(b[i]==b[2])p++;
	if(p==n-1)
	{
		int w=1;
		while(m>=w*(w+1)*b[2]/2)w++;
		cout<<w-1<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	int sum=-1;
	for(int i=2;i<=n;i++) 
	{
		int ans=1,s=m;
		for(int j=i-1;j>=1;j--)
		{
			if(s>=a[i]-a[j])
			{
				ans++;
				s=s-(a[i]-a[j]);
			}
			sum=max(ans,sum);
		}
	}
	cout<<sum<<endl;
	return 0;	
} 
