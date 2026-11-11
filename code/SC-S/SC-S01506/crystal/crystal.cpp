#include<bits/stdc++.h>
using namespace std;

int n,m,maxn=-1;
int a[1000006];

int main()
{freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
sort(a+1,a+n+1); 
for(int i=1;i<=n;i++)
{	int cnt=1;
	for(int j=i;j>=1;j--)
	{
		if(m-a[i]+a[j]>=0)
	    {
		m=m-a[i]+a[j];
		cnt++;
        }
		
	
	}
maxn=max(maxn,cnt);
	
}
cout<<maxn;


return 0;
}