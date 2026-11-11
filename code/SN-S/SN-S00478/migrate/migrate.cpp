//SN-S00478 朱振华 西安市远东第二中学 
#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,d;
int a[1000],b[10000][10000];
int ans=0;
int fly(int now,int to)
{
	int num=0;
	if(a[to]-a[now]<=d)
	{
		num++;
	}
	else
	{
		for(int i=now+1;i<=to-1;i++)
		{
			if(a[i]-a[now]<=d&&a[i]-a[now]<=d)
			{
				num++;
			}
		}
	}
	return num;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>T;
    
	while(T--)
	{
		cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
    	    cin>>a[i];
	    }
	    sort(a,a+n+1);
	    for(int i=1;i<=n-2;i++)
	    {
	    	for(int j=i+2;j<=n;j++)
			{
				b[i][j]=fly(i,j);
			} 
		}
		for(int i=1;i<=n;i++)
		{
			
			for(int j=1;j<=n;j++)
			{
				if(b[i][j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
