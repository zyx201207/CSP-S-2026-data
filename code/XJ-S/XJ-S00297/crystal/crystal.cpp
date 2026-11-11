#include<bits/stdc++.h>
using namespace std;
long long int m,n,i,j,a[8000005],w[5005][5005],p,k=1,c,s,maxn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a,a+n);
	for(j=1;j<=n;j++)
	for(i=1;i<=n;i++)
    {   if(j<i)
        w[j][i]=a[i]-a[j];
        else
    	w[j][i]=a[j]-a[i];
    	
    }
    for(c=1;c<=n;c++)
    {
			for(j=1;j<=n;j++)
    	{s=j;
    		for(i=j+1;i<=n;i++)
    		{	
    			s+=w[c][i];
    			if(s>m)
    			break;
    			if(s==m)
    			{
				p=n-i+1;
				if(p>maxn)
				maxn=p;
				if(maxn==n)
				{
					cout<<maxn;
					return 0;
				}
				}
			}
		}
}
cout<<maxn;
return 0;
 } 
 // 5 5 1 2 4 8 9
// 5 8 -3 -1 2 2 7
