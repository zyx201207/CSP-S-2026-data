#include <iostream>
#include <cstdio>
using namespace std;
int cid,T;
int n;
long long d;
long long a[2000005];
int f[2000005];
long long cnt[2000005],sum[2000005];
int lst[2000005];
long long ans=0;
void work()
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			f[j]=0,lst[j]=0;
			cnt[j]=0,sum[j]=0;
		}
		f[i]=0;
		lst[f[i]]=i;
		cnt[i]=1;
		sum[i]=1;
		int id=i;
		for(int j=i+1;j<=n;j++)
		{
			while(a[j]-a[id]>d) id++;
			if(id>=j) break;
			f[j]=f[id]+1;
			if(sum[lst[f[id]]]-sum[id-1]>2) cnt[j]=10;
			else cnt[j]=sum[lst[f[id]]]-sum[id-1];
			if(cnt[j]==2) ans++;
			lst[f[j]]=j;
			sum[j]=sum[j-1]+cnt[j];
		}
	}
	cout<<ans<<endl;
}
void work2()
{
	for(int j=0;j<=n;j++)
	{
		f[j]=0,lst[j]=0;
		cnt[j]=0,sum[j]=0;
	}
	f[1]=0;
	lst[f[1]]=1;
	cnt[1]=1;
	sum[1]=1;
	int id=1;
	ans=0;
	long long res=0;
	for(int j=2;j<=n;j++)
	{
		while(a[j]-a[id]>d) id++;
		if(id>=j) break;
		f[j]=f[id]+1;
		if(sum[lst[f[id]]]-sum[id-1]>2) cnt[j]=10;
		else cnt[j]=sum[lst[f[id]]]-sum[id-1];
		if(cnt[j]==2) res++;
		lst[f[j]]=j;
		sum[j]=sum[j-1]+cnt[j];
		ans+=res;
	}
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cid>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(cid<=10)
		{
			work();
			continue;
		}
		work2(); 
	}	
	return 0;
}
