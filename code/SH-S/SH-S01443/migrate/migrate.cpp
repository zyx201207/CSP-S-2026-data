#include<bits/stdc++.h>
using namespace std;

int c,t,n;
long long d;
long long x[2000000];

long long ans;
int l_i,r_i,l_c,r_c;
long long l,r;
int a[2000000];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%d %lld",&n,&d);
		for(int i=0;i<n;i++)
			scanf("%lld",&x[i]);
		l=x[0]; l_i=0;
		r=l+d;
		if(r>x[n-1]) r_i=n-1;
		else
		{
			r_i=1;
			while(x[r_i]<=r) r_i++;
			r_i--;
		}
		a[0]=r_i-l_i+1;
		while(r<=x[n-1])
		{
			l++; r++;
			if(l>x[l_i]) l_i++;
			if(r>=x[r_i+1]) r_i++;
			if(l==x[l_i]) a[l_i]=r_i-l_i+1;
		}
		for(int i=l_i;i<n;i++)
			a[i]=n-i;
		l_i=r_i=-1;
		int l_j,r_j;
		for(int i=0;i<n;i++)
		{
			if(a[i]==3)
			{
				if(l_i==-1)
				{
					l_i=i;
				}
				else
				{
					l_c=r_c=1;
					l_j=l_i-1;
					r_j=r_i+3;
					while(a[l_j]==2)
					{
						l_j--;
						l_c++;
					}
					while(a[r_i]==2)
					{
						r_j++;
						r_c++;
					}
					ans+=l_c*r_c;
				}
			}
			else if(a[i]>3 || a[i]<2)
			{
				l_i=-1;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
