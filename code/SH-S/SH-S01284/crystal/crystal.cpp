#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
long long sto[N],qianzhuihe[N];
long long n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>sto[i+1];
	}
	sto[1]=-2e18;//保证即使第一个数为-1e12也能表达无法无法调整，且前缀和不超过-3e18合法 
	n++;
	sort(sto+1,sto+n+1);
	for(int i=1;i<=n;i++)
	{
		qianzhuihe[i]=qianzhuihe[i-1]+sto[i];
	}
	long long ans=1;
	for(long long i=2;i<=n;i++)
	{
		long long l=1,r=i+1;
		while(l<r-1)//[mid,i]之间的所有数改变要多少代价 
		{
			//cout<<l<<endl;
			long long mid=(l+r)/2;
			long long c=i-mid+1;
			long long p=sto[i]*c-(qianzhuihe[i]-qianzhuihe[mid-1]);
			//cout<<i<<" "<<mid<<" "<<p<<endl;
			if(p<=m)r=mid;
			else l=mid;
		}
		//cout<<"i="<<i<<" l+1="<<l+1<<" p="<<sto[i]*(i-l)-(qianzhuihe[i]-qianzhuihe[l])<<endl;
		ans=max(ans,0LL+i-l+1-1);
	}
	cout<<ans<<endl;
	return 0;
} 
