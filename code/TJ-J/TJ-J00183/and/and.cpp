#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(m==2)
	{
		int maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				maxx=max(maxx,a[i]&a[j]);
			}
		cout << maxx;
	}
	else if(m==3)
	{
		int maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
				{
					if(i==j||i==k||j==k) continue;
					maxx=max(maxx,(a[i]&a[j])&a[k]);
				}
		cout << maxx;
	}
	else if(m==4)
	{
		int maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					for(int l=1;l<=n;l++)
					{
						if(i==j||i==k||j==k||i==l||j==l||l==k) continue;
						maxx=max(maxx,((a[i]&a[j])&a[k])&a[l]);
					}
		cout << maxx;
	}
	else if(m==5)
	{
		int maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					for(int l=1;l<=n;l++)
						for(int q=1;q<=n;q++)
						{
							if(i==j||i==k||j==k||i==l||j==l||l==k||i==q||j==q||k==q||l==q) continue;
							maxx=max(maxx,(((a[i]&a[j])&a[k])&a[l])&a[q]);
						}
		cout << maxx;
	}
	else if(m==6)
	{
		int maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					for(int l=1;l<=n;l++)
						for(int q=1;q<=n;q++)
							for(int w=1;w<=n;w++)
							{
								if(i==j||i==k||j==k||i==l||j==l||l==k||i==q||j==q||k==q||l==q||i==w||j==w||k==w||l==w||q==w) continue;
								maxx=max(maxx,((((a[i]&a[j])&a[k])&a[l])&a[q])&a[w]);
							}
		cout << maxx;
	}
	else if(m==7)
	{
		int maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					for(int l=1;l<=n;l++)
						for(int q=1;q<=n;q++)
							for(int w=1;w<=n;w++)
								for(int p=1;p<=n;p++)
								{
									if(i==j||i==k||j==k||i==l||j==l||l==k||i==q||j==q||k==q||l==q||i==w||j==w||k==w||l==w||q==w||i==p||j==p||k==p||l==p||q==k||w==k) continue;
									maxx=max(maxx,(((((a[i]&a[j])&a[k])&a[l])&a[q])&a[w])&a[p]);
								}
		cout << maxx;
	}
	else if(m==1) cout << 1;
	else
	{
		sort(a+1,a+n+1);
		cout << a[n-m+1];
	} 
	return 0;
}
