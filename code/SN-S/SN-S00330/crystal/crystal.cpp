//罗何烨 西安中学 SN-S00330 
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
long long n,m,num,ans,k;
long long a[N],b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;--i)
	{
		for(int j=1;j<=i;++j)
		{
			b[j]=a[i]-a[j];
		}
		num=0;
		k=i;
		for(long long j=1;;j++)
		{
			num=num+b[k];
			k--;
			if(num<=m)
			{
				ans=max(ans,j);
			}
			else
			{
				break;
			}
			if(k==0)
			{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
	
}
