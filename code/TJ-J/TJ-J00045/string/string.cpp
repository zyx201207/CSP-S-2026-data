#include <bits/stdc++.h>
using namespace std;
int n;
long long len,l[200005],r[200005],fl[200005],fr[200005];
char c[200005],fc[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		long long d;
		cin>>d>>c[i];
		len+=d;
		l[i]=len-d+1;
		r[i]=len;
	}
	long long mid=(len+1)/2,pos;
	for (int i=1;i<=n;i++)
	{
		if (l[i]<=mid && r[i]>mid)
		{
			n++;
			long long x=mid+1,y=r[i],o=0;
			char oo,z=c[i];
			r[i]=mid;
			for (int j=i+1;j<=n;j++)
			{
				o=r[j];
				l[j]=x;
				r[j]=y;
				x=r[j]+1;
				y=o;
				oo=c[j];
				c[j]=z;
				z=oo;
			}
			pos=i;
			break;
		}
		if (l[i]>mid)
		{
			pos=i-1;
			break;
		}
	}
	int top=0;
	for (int i=n;i>=pos+1;i--)
	{
		fl[++top]=len-r[i]+1;
		fr[top]=len-l[i]+1;
		fc[top]=c[i];
	}
	
	long long ans=0;
	for (int i=1,j=1;i<=pos && j<=top;)
	{
		if (fr[j]<r[i])
		{
			if (fc[j]!=c[i])
			{
				ans+=fr[j]-max(fl[j],l[i])+1;
			}
			j++;
		}
		else if (fr[j]==r[i])
		{
			if (fc[j]!=c[i])
			{
				ans+=fr[j]-max(fl[j],l[i])+1;
			}
			i++;
			j++;
		}
		else
		{
			if (fc[j]!=c[i])
			{
				ans+=r[i]-max(fl[j],l[i])+1;
			}
			i++;
		}
	}
	cout<<ans;
	return 0;
}
