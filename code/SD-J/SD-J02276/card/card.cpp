#include<bits/stdc++.h>
using namespace std;
int a[5000010];
int b[5000010];
int c[5000010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(n--)
	{
		int k;
		for(int i=1;i<=n;i++)
		{
			k=1;
			int r=1,l=k-1;
			while(r<=l)
			{
				int mid=(r+l)/2;
				if(a[mid]>a[k]) r=mid-1;
				if(a[mid]<a[k]) l=mid+1;
				if(a[mid]==a[k])
				{
					for(int j=mid;j<k;j++) b[j]=0;
					k=mid;
					b[k]=a[i];
					break;
				} 
			}
			b[k]=a[i];
			k++;
		}	
		for(int i=1;i<=k;i++) c[b[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
} 
