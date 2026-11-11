#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int a[500100],sum[500100];int n,m;
inline bool cmp(int x,int y)
{
	return x>y;
}
bool sub1=1,sub2=1,sub3=1;
int d;
inline void subtask()
{
//	cout<<"XXX"<<'\n';
	for(int i=1;i<=n;i++)
	{
		a[i]=a[n]-a[i];
	}
	int num=0,cnt=0;
	for(int i=n;i>=1;i--)
	{
		num+=a[i];
		if(num>m)
		{
			cout<<cnt;
			return ;
		}
		cnt++;
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
//		if(abs(a[i])>100)sub1=0;
		if(i==2)d=a[2]-a[1];
		if(i!=1&&i!=2&&a[i]-a[i-1]!=d)sub3=0;
	}
	if(n>50000&&sub3)
	{
		subtask();
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		int base=a[i];
		int l=i,r;
		for(r=l;r<=n;r++)
		{
			int len=r-l+1;
			if(base*len-(sum[r]-sum[l-1])>m)
			{
				r--;
				break;
			}
		}
		r=min(r,n);
		ans=max(ans,r-l+1);
	}//真是搞笑，退役一年，思维没弱化，二分不会写了，T1没有全分就算是对自己的惩罚吧 
	cout<<ans;
} 
