#include<bits/stdc++.h>
using namespace std;
int n,m;
int two(int x)
{
	int ans=0,y=2;
	while(x>0)
	{
		y*=10;
		y+=(x%2);
		x/=2;
	}
	while(y>=10)
	{
		if(y%10!=2)
		{
			ans=ans*10+(y%10);
			y/=10;
		}
	}
	return ans;
}
int maxx;
int a[200010],b[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	srand(time(0));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>b[i];
    	a[i]=two(b[i]);
    	if(b[i]>=maxx)
    	{
    		maxx=b[i];
		}
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	cout<<min(a[rand()],(rand()));
  return 0;
}