#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500100],t[300100],c[500100],b;
bool fla=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];c[i]=a[i];
		if(a[i-1]>a[i])fla=0;
	}
	if(fla==1)
	{
		for(int i=1;i<=m;i++)cout<<i<<' ';
	}else if(n<=5&&m<=2)
	{
		if(m==1)
		cout<<n;
		if(m==2)
		{
		//	1 2 2 1 1
			b=n;
			while(b!=0){
				for(int i=1;i<=n;i++)a[i]=c[i];
				for(int i=n-b+1;i<=n;i++)
				{
					for(int j=n-b+1;j<i;j++)
					{
						if(a[i]==a[j]&&a[i]!=-1){
						for(int k=j;k<i;k++)a[k]=-1;
						}
					}
				}
				for(int i=n-b+1;i<=n;i++)
				{
					if(a[i]!=-1)
					t[a[i]]++;
				}
				b--;
			}
			for(int i=1;i<=m;i++)
			{
				cout<<t[i]<<' ';
			}
		}
	}
	else{
		b=n;
		while(b!=0){
			for(int i=1;i<=n;i++)a[i]=c[i];
			for(int i=n-b+1;i<=n;i++)
			{
				for(int j=n-b+1;j<i;j++)
				{
					if(a[i]==a[j]&&a[i]!=-1){
						for(int k=j;k<i;k++)a[k]=-1;
					}
				}
			}
			for(int i=n-b+1;i<=n;i++)
			{
				if(a[i]!=-1)
				t[a[i]]++;
			}
			b--;
		}
		for(int i=1;i<=m;i++)
		{
			cout<<t[i]<<' ';
		}
	}
	return 0;
}
