#include<bits/stdc++.h>
using namespace std;
int c,t,n,w,l[2000005],r[2000005];
long long d,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(11<=c and c<=12)
		{
			if(d<2*(a[2]-a[1]))
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<max(n-2*(d/(a[2]-a[1]))+1,(long long)0)<<endl;
			}
			continue;
		}
		w=1;
		for(int i=1;i<=n;i++)
		{
			while(w<=n and a[i]-a[w]>d)
			{
				r[w]=i-1;
				w++;
			}
		}
		for(int i=w;i<=n;i++)
		{
			r[i]=n;
		}
		w=n;
		for(int i=n;i>=1;i--)
		{
			while(w>=1 and a[w]-a[i]>d)
			{
				l[w]=i+1;
				w--;
			}
		}
		for(int i=w;i>=1;i--)
		{
			l[i]=1;
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<l[i]<<" "<<r[i]<<endl;
//		}
		if(13<=c and c<=14)
		{
			int l1=1,r1=n,numm=1;
			while(l1<r1)
			{
				int mid=(l1+r1)>>1;
				if(l[mid]>1)
				{
					r1=mid-1;
				}
				else if(r[mid]<n)
				{
					l1=mid+1;
				}
				else
				{
					l1=mid;
					r1=mid;
				}
			}
			if(l[l1+1]==1)
			{
				numm++;
				if(l[l1+2]==1)
				{
					numm++;
				}
			}
			if(r[l1-1]==n)
			{
				numm++;
				if(r[l1-2]==n)
				{
					numm++;
				}
			}
			if(numm>=3)
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<(l[l1+1]-1)*(r[l1-1]-r[l1-2])+(n-r[l1-1])*(l[l1+2]-l[l1+1])<<endl;
			}
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				int k=r[i],la=i,numm=0;
				int j=r[i]+1;
				while(r[k]<j)
				{
					if(r[k]==k)
					{
						numm=2;
						break;
					}
					if(min(j,r[k-1])==min(j,r[k]))
					{
						numm++;
						if(min(j,r[k-2])==min(j,r[k]))
						{
							numm++;
						}
						if(la-1>=i and r[la-1]>=k-1)
						{
							numm++;
						}
					}
					if(numm>1)
					{
						break;
					}
					la=k;
					k=r[k];
				}
				if(numm>1)
				{
					continue;
				}
				for(j=r[i]+1;j<=n;j++)
				{
					while(r[k]<j)
					{
						if(r[k]==k)
						{
							numm=2;
							break;
						}
						if(min(j,r[k-1])==min(j,r[k]))
						{
							numm++;
							if(min(j,r[k-2])==min(j,r[k]))
							{
								numm++;
							}
							if(la-1>=i and r[la-1]>=k-1)
							{
								numm++;
							}
						}
						if(numm>1)
						{
							break;
						}
						la=k;
						k=r[k];
					}
					if(numm>1)
					{
						break;
					}
					int nummm=numm;
					if(min(j,r[k-1])==min(j,r[k]))
					{
						nummm++;
						if(min(j,r[k-2])==min(j,r[k]))
						{
							nummm++;
						}
						if(la-1>=i and r[la-1]>=k-1)
						{
							nummm++;
						}
					}
					if(nummm==1)
					{
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
