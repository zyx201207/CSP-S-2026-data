#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m,k,a[10005];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int i=i-1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==k)
			{
				if(k==0)
				{
					k++;
				}
				else
				{
					k+=a[i];
					k=0;
				}
				a[i]++;
			}
			if(a[i]+=n)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i]==a[n]&&a[i]==a[m])
					{
						a[i]+=a[n];
						a[i]-=a[m];
					}
					if(a[i]+=a[m])
					{
						a[i]==a[m];
					} 
					if(a[i]+=a[n])
					{
						break;
					}
				}
			}
			cout<<i;
		}
	}
	return 0;
}
