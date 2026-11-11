#include <bits/stdc++.h>
using namespace std;
int n,m,x,MAX,MAX2,cnt,cnt2,ans;
int a[200010][40],b[200010],c[200010],d[200010];
long long q,sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt=0;
		while(x>0)
		{
			cnt++;
			if(x%2==1) c[cnt]++;
			if(c[cnt]>=m) MAX=max(MAX,cnt);
			a[i][cnt]=x%2;
			x/=2;
		}
	}
	cnt=0;
	for(int i=1;i<=n;i++)
	  if(a[i][MAX]==1)
	  {
	  		cnt++;
	  		b[cnt]=i;
	  }
	d[MAX]=1;
	MAX2=MAX;
	MAX--;
	cnt2=cnt;
	while(MAX>0)
	{
		ans=0;
		for(int i=1;i<=cnt;i++) 
		  if(b[i]!=-1&&a[b[i]][MAX]==1) ans++;
		if(ans>=m) d[MAX]=1;
		if(ans>=m&&cnt2>m)
		  for(int i=1;i<=cnt;i++)
		    if(b[i]!=-1&&a[b[i]][MAX]==0) 
		    {
		    	cnt2--;
		    	b[i]=-1;
			}
		MAX--;
	}
	q=1;
	for(int i=1;i<=MAX2;i++) 
	{
		sum+=d[i]*q;
		q*=2;
	}
	cout<<sum<<endl;
	return 0;
}
