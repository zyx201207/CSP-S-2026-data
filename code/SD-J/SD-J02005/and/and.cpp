#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n],max=INT_MIN;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			if(max<a[i]) max=a[i];
		}
	}
	else if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if((a[i] & a[j])>max && a[i]!=a[j]) max=(a[i] & a[j]);
			}
		}
	}
	else if(m==3)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				for(int k=j;k<n;k++)
				{
					if((a[i] & a[j] & a[k])>max && a[i]!=a[j] && a[j]!=a[k] && a[i]!=a[k]) max=(a[i] & a[j] & a[k]);
				}
			}
		}
	}
	else if(m==4)
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
				for(int k=j;k<n;k++)
					for(int x=k;x<n;x++)
						if((a[i] & a[j] & a[k] & a[x])>max && a[i]!=a[j] && a[j]!=a[k] && a[i]!=a[k] && a[i]!=a[x] && a[j]!=a[x] && a[k]!=a[x]) max=(a[i] & a[j] & a[k] & a[x]);
	else if(m==5)
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
				for(int k=j;k<n;k++)
					for(int x=k;x<n;x++)
						for(int b=x;b<n;b++)
							if((a[i] & a[j] & a[k] & a[x] & a[b])>max && a[i]!=a[j] && a[j]!=a[k] && a[i]!=a[k] && a[i]!=a[x] && a[j]!=a[x] && a[k]!=a[x] && a[i]!=a[b] && a[j]!=a[b] && a[k]!=a[b] && a[x]!=a[b]) max=(a[i] & a[j] & a[k] & a[x] & a[b]);
	else if(m==6)
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
				for(int k=j;k<n;k++)
					for(int x=k;x<n;x++)
						for(int b=x;b<n;b++)
							for(int c=b;c<n;c++)
							if((a[i] & a[j] & a[k] & a[x] & a[b] & a[c])>max && a[i]!=a[j] && a[j]!=a[k] && a[i]!=a[k] && a[i]!=a[x] && a[j]!=a[x] && a[k]!=a[x] && a[i]!=a[b] && a[j]!=a[b] && a[k]!=a[b] && a[x]!=a[b] && a[i]!=a[c] && a[j]!=a[c] && a[k]!=a[c] && a[x]!=a[c] && a[b]!=a[c]) max=(a[i] & a[j] & a[k] & a[x] & a[b] & a[c]);
	else if(m==7)
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
				for(int k=j;k<n;k++)
					for(int x=k;x<n;x++)
						for(int b=x;b<n;b++)
							for(int c=b;c<n;c++)
								for(int d=c;d<n;d++)
									if((a[i] & a[j] & a[k] & a[x] & a[b] & a[c] & a[d])>max && a[i]!=a[j] && a[j]!=a[k] && a[i]!=a[k] && a[i]!=a[x] && a[j]!=a[x] && a[k]!=a[x] && a[i]!=a[b] && a[j]!=a[b] && a[k]!=a[b] && a[x]!=a[b] && a[i]!=a[c] && a[j]!=a[c] && a[k]!=a[c] && a[x]!=a[c] && a[b]!=a[c] && a[i]!=a[d] && a[j]!=a[d] && a[k]!=a[d] && a[x]!=a[d] && a[b]!=a[d] && a[c]!=a[d]) max=(a[i] & a[j] & a[k] & a[x] & a[b] & a[c] & a[d]);
	else if(m==8)
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
				for(int k=j;k<n;k++)
					for(int x=k;x<n;x++)
						for(int b=x;b<n;b++)
							for(int c=b;c<n;c++)
								for(int d=c;d<n;d++)
									for(int e=d;e<n;e++)
										if((a[i] & a[j] & a[k] & a[x] & a[b] & a[c] & a[d] & a[e])>max && a[i]!=a[j] && a[j]!=a[k] && a[i]!=a[k] && a[i]!=a[x] && a[j]!=a[x] && a[k]!=a[x] && a[i]!=a[b] && a[j]!=a[b] && a[k]!=a[b] && a[x]!=a[b] && a[i]!=a[c] && a[j]!=a[c] && a[k]!=a[c] && a[x]!=a[c] && a[b]!=a[c] && a[i]!=a[d] && a[j]!=a[d] && a[k]!=a[d] && a[x]!=a[d] && a[b]!=a[d] && a[c]!=a[d] && a[i]!=a[e] && a[j]!=a[e] && a[k]!=a[e] && a[x]!=a[e] && a[b]!=a[e] && a[c]!=a[e] && a[d]!=a[e]) max=(a[i] & a[j] & a[k] & a[x] & a[b] & a[c] & a[d] &a[e]);
	cout<<max<<" ";
	return 0;
}
