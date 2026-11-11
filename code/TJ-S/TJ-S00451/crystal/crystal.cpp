#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],f[500009];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	scanf("%lld""%lld",&n,&m);
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);	
	}
	for(int i=2;i<=n;i++)
	{
		f[i]=abs(a[i]-a[i-1]);
	}
	sort(a+1,a+n+1);
	sort(f+1,f+n+1);
	for(int i=1;i<=n;i++)
	{
//		cout<<"f[i]:"<<f[i]<<" ";
//		d+=f[i];
	}
	long long sum=1;
	for(int i=2;i<=n;i++)
	{
		if(m-f[i]<0)
		{
			break;
		}
//		cout<<"f[i]11:"<<f[i]<<"\n";
		if(f[i]==f[i-1])
		{
			sum++;
//			cout<<"111"<<"\n";
//			cout<<"f[i]:"<<f[i]<<" "<<i<<" "<<a[i-1]<<"\n\n";
			f[i+1]+=f[i];	
			continue;
		}
		else if(m-f[i]>=0)
		{
			sum++;
//			cout<<"222"<<"\n";
			m-=f[i];
			f[i+1]+=f[i];
		}
	} 
	printf("%lld",sum);
	return 0;
}
