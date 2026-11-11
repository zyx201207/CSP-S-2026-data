#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,n,m,a[1000005],ans=0,x,y;
char c[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(i=1,j=n;i<j;)
	{
		x=a[i];
		y=a[j];
		if(c[i]!=c[j])
		{
			ans+=min(a[i],a[j]);
		}
		a[i]-=min(x,y);
		a[j]-=min(x,y);
		if(a[i]==0)
		i++;
		if(a[j]==0)
		j--;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
