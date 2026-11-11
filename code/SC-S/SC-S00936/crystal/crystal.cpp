#include <bits/stdc++.h>
using namespace std;

const int MAX=5*1e5;
int n,m,a[MAX],x,y,c=1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    	for(int j=i+1;j<=n;j++)
    		if(a[i]==a[j])
    			c++;
    for(int i=2;i<=n;i++)
	{
		x=a[i];
		int q=m;
		for(int j=1;j<=n;j++)
		{
			if(x>=a[j])
			{
				if(x==a[j])
					y++;
				
				q=q-(x-a[j]);
				y++;
				if(q==0)
				{
					cout<<y+c;
					return 0;
				}
			}
			
		}
		y=0;
	}

    return 0;
}

