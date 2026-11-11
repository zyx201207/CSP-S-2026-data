#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
const int N=4e5+10;
int n,mid,a[N],cnt,sum,s[N],ans;
int l,r;
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		++cnt;
		cin>>a[cnt]>>c[cnt];
		if(c[cnt]==c[cnt-1])
		{
			a[cnt-1]+=a[cnt];
			cnt--;
		}
	}l=1;r=cnt;
	while(l<r)
	{
		if(a[l]==0){l++;continue;}
		if(a[r]==0){r--;continue;}
		if(a[l]==a[r]&&c[l]!=c[r])ans+=a[l];
		if(a[l]>a[r])
		{
			sum=a[l];
			while(sum&&l<r)
			{
				if(a[r]>sum)
				{
					a[r]-=sum;
					if(c[l]!=c[r])ans+=sum;
					sum=0;
					break;
				}
				sum-=a[r];
				if(c[l]!=c[r])ans+=a[r];
				a[r]=0;
				r--;
			}r++;
		}
		if(a[r]>a[l])
		{
			sum=a[r];
			while(sum&&l<r)
			{
				if(a[l]>sum)
				{
					a[l]-=sum;
					if(c[l]!=c[r])ans+=sum;
					sum=0;
					break;
				}
				sum-=a[l];
				if(c[l]!=c[r])ans+=a[l];
				a[l]=0;
				l++;
			}l--;
		}
//		cout<<l<<' '<<r<<' '<<ans<<'\n';
		l++,r--;
	}
	cout<<ans;
	return 0;
}
