#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],cha[N],maxx=-1;
int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	if(n<=5000)
	{
		for(int kk=1;kk<=n;kk++)
		{
			sort(a+1,a+1+n);
			for(int i=1;i<n;i++) 
			cha[i]=a[i+1]-a[i];
			long long ans=1;
			for(int j=kk;j<n;j++)
			{
				if(m>=cha[j])
				{
					m-=cha[j]*ans;
					ans++;
					a[j]+=a[j+1];
					a[j+1]=0;
				}
			}
			maxx=max(maxx,ans);
		}	
		cout<<maxx;
	}
	else
	{
		long long ans=1;
		sort(a+1,a+1+n);
		long long x=a[2]-a[1],k=a[1];
		if(m<x){cout<<1;return 0;}
		bool p=true;
		for(long long i=2;i<n;i++)
			if(a[i+1]-a[i]!=x)
			{
				p=false;
				break;
			}
		if(p==true)
		{
			while(m>x)
			{
				ans++;
				m-=x;
				k+=x;
			}
			while(k<=n)
			{
				ans++;
				k+=k;
			}
			cout<<ans;
		}
		else cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
