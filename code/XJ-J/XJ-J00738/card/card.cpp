#include<bits/stdc++.h>
using namespace std;

long long int n,m,a[500005],b[500005],c[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j,jn,k,s;
	cin >> n >> m;
	for (i=1; i<=n; i++)
		cin >> a[i];
	for (i=0; i<m; i++)
	{
		s=0;
		for (j=i+1; j<=n; j++)
		{
			bool f=true;
			for (k=1; k<j; k++)
				if (a[k]==a[j+jn])
				{
					jn=j-k; j=k; f=false;
					break;
				}
			if (f)
				b[++s]=a[j+jn];
		}
		sort(b+1,b+1+n);
		for (j=1; j<=s; j++)
			c[b[j]]++;
	}
	for (i=1; i<=m; i++)
		if (c[i]!=0)
			cout << c[i] << ' ';
	return 0;
}
