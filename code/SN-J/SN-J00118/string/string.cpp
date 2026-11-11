#include<bits/stdc++.h>
using namespace std;
long long n,len,sum=0,cnt1,cnt2,x=1,ans=0;
bool bl;

struct node{
	int sum;
	char c;
}a[200005],b[200005],c[200005];

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c[i].sum>>c[i].c;
		len+=c[i].sum;
	}
	for(int i=0;i<n;i++)
	{
		sum+=c[i].sum;
		if(sum>len/2&&!bl)
		{
			if(sum-c[i].sum!=len/2)
			{
				a[++cnt1].sum=len/2-sum+c[i].sum;
				a[cnt1].c=c[i].c;
			}
			b[++cnt2].sum=sum-len/2;
			b[cnt2].c=c[i].c;
			if(len%2)
			{
				b[cnt2].sum--;
			}
			bl=true;
			continue;
		}
		if(!bl)
		{
			a[++cnt1].sum=c[i].sum;
			a[cnt1].c=c[i].c;
		}
		else
		{
			b[++cnt2].sum=c[i].sum;
			b[cnt2].c=c[i].c;
		}
	}
	reverse(b+1,b+cnt2+1);
	sum=0,ans=0;
	for(int i=1;i<=cnt2;i++)
	{
		sum+=b[i].sum;
		if(sum==a[x].sum)
		{
			if(b[i].c!=a[x].c)
			{
				ans+=b[i].sum;
			}
			x++;
			sum=0;
			continue;
		}
		if(sum>a[x].sum)
		{
			if(a[x].c!=b[i].c)
			{
				ans+=b[i].sum-sum+a[x].sum;
			}
			b[i].sum=sum-a[x].sum;
			i--;
			sum=0;
			x++;
			continue;
		}
		if(b[i].c!=a[x].c)
		{
			ans+=b[i].sum;
		}
	}
	cout<<ans;
	return 0; 
}
