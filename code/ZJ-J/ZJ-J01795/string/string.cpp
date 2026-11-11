#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,sum,ans,m,j,k,l,r,a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
		if(c[i]==c[i-1])
		{
			a[i-1]+=a[i];
			i--;
			n--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans+=a[i];
		if(ans>=(sum+1)/2)
		{
			m=i;
			k=ans-(sum+1)/2;
			break;
		}
	}
	if(sum&1)
	{
		a[m]--;
		if(!a[m])
		{
			for(int i=m;i<n;i++)
			{
				a[i]=a[i+1];
				c[i]=c[i+1];
			}
			n--;
		}
		if(k!=0&&k!=a[m])
		{
			a[m]-=k;
			n++;
			for(int i=n;i>m;i--)
			{
				a[i]=a[i-1];
				c[i]=c[i-1];
			}
			a[m+1]=k;
		}
		else m--;
	}
	else
	{
		if(k!=0)
		{
			a[m]-=k;
			n++;
			for(int i=n;i>m;i--)
			{
				a[i]=a[i-1];
				c[i]=c[i-1];
			}
			a[m+1]=k;
		}
	}
	ans=k=0;
	l=1;r=n;
	j=a[l];k=a[r];cout<<m<<'\n';
	while(l<=m&&r>m)
	{
		if(c[l]!=c[r])ans+=min(j,k);
		if(j>k)
		{
			j-=k;
			r--;
			k=a[r];
		}
		else if(k>j)
		{
			k-=j;
			l++;
			j=a[l];
		}
		else
		{
			l++;r--;
			j=a[l];k=a[r];
		}
	}
	cout<<ans;
	return 0;
}
