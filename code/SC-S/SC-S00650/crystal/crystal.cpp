#include<bits/stdc++.h>
using namespace std;
int a[50010];
int c[50010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int b=1;
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[i-1])
		{
			b=0;
		}
	}
	if(b==1)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i<=(n+1)/2) 
		{
	    	c[i]=a[(n+1)/2]-a[i];
		}
		else
		{
	    	c[i]=a[i]-a[(n+1)/2];
		} 
	}
	sort(c+1,c+n+1);
	int cnt=0;
	int s=1;
	while(m!=0)
    {
    	m-=c[s];
        s++;
    	cnt++;
    }
    cout<<cnt;
	return 0;
}