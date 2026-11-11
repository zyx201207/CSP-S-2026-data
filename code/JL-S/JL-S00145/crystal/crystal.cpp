#include<bits/stdc++.h>
using namespace std;
#define N 5123456
long long n,gs,m,a[N],s[N],maj,cnt[220],ww,sum;
bool cmp(long long a1,long long b1)
{
	return a1<b1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ma=LONG_LONG_MIN;
	sort(a+1,a+n+1,cmp);
	if(n<=5000){
	for(long long i=1;i<=n;i++)
	{
		long long wz,m1;
		m1=m;
		wz=1;
		while(i+wz<n&&m1>=wz*(a[i+wz]-a[i+wz-1]))
		{
			m1-=wz*(a[i+wz]-a[i+wz-1]);
			wz++;
		}
		ma=max(wz,ma);
	}
	cout<<ma<<endl;
	}
	else if(a[n]>100)
	{
		long long k=1;
		while(k+1<=n&&m>=k*(a[k+1]-a[k]))
		{
			m-=k*(a[k+1]-a[k]);
			k++;
		}
		cout<<k<<endl;
	}
	else 
	{
		for(long long i=1;i<=n;i++)
		cnt[a[i]+100]++;
		gs=0;
		for(long long i=0;i<=200;i++)
		{
			if(cnt[i]==0)continue;
			sum=cnt[i];
			long long m2=m;
			while(sum+gs+1<=n&&m2>=sum*(a[sum+gs+1]-a[sum+gs]))
			{	
				m2-=sum*(a[sum+gs+1]-a[sum+gs]);
				sum+=cnt[a[sum+gs+1]+100];
			}
			if(sum>ma){
			ma=sum;
			maj=gs;
			}
			gs+=cnt[i];
		}
		
		for(long long i=maj+1;a[i]==a[maj+1];i++)
		{
			long long wz1,m11;
			m11=m;
			wz1=1;
			while(i+wz1<n&&m11>=wz1*(a[i+wz1]-a[i+wz1-1]))
			{
				m11-=wz1*(a[i+wz1]-a[i+wz1-1]);
				wz1++;
			}
			ma=max(wz1,ma);
		}
		cout<<ma<<endl;
	}
	return 0;
}
