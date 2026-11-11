#include<iostream>
#include<string>
using namespace std;
char c[200005];
int n;
long long a[200005],ans,l,r,ret;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	ret=0;
	while(l<=r)
	{
		if(a[l]>a[r]-ret)
		{
			long long reg=a[l]-a[r];
			if(c[l]!=c[r])ans+=a[r];
			while(reg>0)
			{
				if(reg>a[--r])
				{
					if(c[l]!=c[r])ans+=a[r];
					reg-=a[r];
				}
				else
				{
					ret=a[r]-reg;
					if(c[l]!=c[r])ans+=reg;
					reg=0;
				}
			}
		}
		else
		{
			if(c[l]!=c[r])ans+=a[l];
			ret+=a[l];
		}
		l++;
	}
	cout<<ans;
	return 0;
}
