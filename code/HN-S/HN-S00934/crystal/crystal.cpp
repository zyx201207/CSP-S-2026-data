#include <bits/stdc++.h>
using namespace std;
int n,m,a[500008];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];	
	}
	int duo=1; 
	for(int i=n;i>=1;i--)
	{
		int num=0;
		int ans=m;
		for(int j=i;j>=1;j--)
		{
		    if(a[i]-a[j]>=ans)
		    {
			    num++;
			    int cha=a[i]-a[j];
			    ans-=cha;
		    }
		}
		duo=max(duo,num);
	}
	cout<<duo;
	return 0;
}
