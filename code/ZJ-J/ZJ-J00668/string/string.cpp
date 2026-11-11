#include<bits/stdc++.h>
using namespace std;
long long n,a[1000010],l[100010],r[1000010];
long long mid;
char c[1000010],lc[1000010],rc[1000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		mid+=a[i];
	}
	mid/=2;
	long long ml=mid;
	for(int i=1;i<=n;i++)
	{
		if(mid>=a[i])
		{
			l[i]=a[i];
			lc[i]=c[i];
			mid-=a[i];
		}
		else
		{
			l[i]=mid;
			lc[i]=c[i];
			mid=0;
		}
		if(mid==0)
		{
			break;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(ml>=a[i])
		{
			r[n-i+1]=a[i];
			rc[n-i+1]=c[i];
			ml-=a[i];
		}
		else
		{
			r[n-i+1]=ml;
			rc[n-i+1]=c[i];
			ml=0;
		}
		if(ml==0)
		{
			break;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<l[i]<<lc[i]<<endl;
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<r[i]<<rc[i]<<endl;
//	}
//	cout<<endl;
	long long sum=0,le=1,ri=1;
	for(;1;)
	{
		if(lc[le]!=rc[ri])
		{
			sum+=min(l[le],r[ri]);
//			cout<<lc[le]<<" "<<rc[ri]<<" "<<sum<<endl;
		}
		long long summ=min(l[le],r[ri]);
		l[le]-=summ;
		r[ri]-=summ;
		if(l[le]==0)
		{
			le++;
		}
		if(r[ri]==0)
		{
			ri++;
		}
		if(l[le]==0||r[ri]==0)
		{
			break;
		}
	}
	cout<<sum;
	return 0;
}