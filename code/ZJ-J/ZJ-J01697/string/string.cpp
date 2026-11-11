#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],cnt,k,id,m,i,j;
char c[100010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(n%2)m=n/2+1;
	else m=n/2;
	i=1;j=n;
	k=a[1];id=1;
	while(i<=j)
	{
		if(id<=m)
		{
			if(k<a[j])
			{
				if(c[i]!=c[j])cnt+=k;
				k=a[j]-k;
				id=j;
				i++;
			}
			else
			{
				if(c[i]!=c[j])cnt+=a[j];
				k=k-a[j];
				j--;
			}	
		}
		else
		{
			if(k<a[i])
			{
				if(c[i]!=c[j])cnt+=k;
				k=a[i]-k;
				id=i;
				j--;
			}
			else
			{
				if(c[i]!=c[j])cnt+=a[i];
				k=k-a[i];
				i++;
			}
		}
	}
	cout<<cnt;
 	return 0;
}
