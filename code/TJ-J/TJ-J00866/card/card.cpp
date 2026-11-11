#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m,tsa=1,a[500005],diff[300005],ned,
ca[500005],p,
pos[300005],h,st[500005],ans[300005];

void nsm()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		    pos[j]=-1;
		for(int j=1;j<=n;j++)
			st[j]=0;
		h=0;
		for(int j=1;j<=n;j++)
		{
			if(j<=i-1)
				continue;
			if(pos[a[j]]!=-1)
			{
				int paj=pos[a[j]];
				for(int k=pos[a[j]];k<=h;k++)
				{
					pos[st[k]]=-1;
					st[k]=0;
				}
				h=paj;
			}
			h++;
			st[h]=a[j];
			pos[a[j]]=h;
		}
		for(int j=1;j<=h;j++)
		    ans[st[j]]++;	
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}

void ftsa()
{
	for(int i=1;i<=n;i++)
		diff[a[i]]++;
	int ss=0;
	for(int i=1;i<=m;i++)
	{
		ss+=diff[i];
		cout<<ss<<" ";
	}
}

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	    if(a[i]<a[i-1])
	    	tsa=0;
	    if(a[i]!=a[i-1])
	    	ned++;
	}
	if(n<=5000)
		nsm();
	else if(tsa)
		ftsa();
	else 
		nsm();
	return 0;
}
