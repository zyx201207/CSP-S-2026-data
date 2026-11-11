#include<bits/stdc++.h>
using namespace std;
long long n,i,s,k,a[1000000],maxn1,maxn2;
char c[1000000];
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i]>>c[i];
	i=1;k=n;
	while(i!=k)
	{
		if(a[i]==0)
		i++;
		if(a[k]==0)
		k--;
		cout<<c[i]<<" "<<c[k]<<endl;
		if(c[i]==c[k])
		{
			a[i]-=a[i];
			a[k]-=a[k];
		}
		if(c[i]!=c[k])
		{
			maxn1=a[i]-a[k];
			maxn2=a[k]-a[i];
			if(maxn1>maxn2)
			{
				s+=a[k];
				a[i]-=a[k];
			}
			else
			{
				s+=a[i];
				a[k]-=a[i];
			}
		}
	}
	cout<<s;
	return 0;
}