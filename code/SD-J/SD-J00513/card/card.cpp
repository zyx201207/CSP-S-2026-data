#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],num,nun,l,z[500005];
int main()
{
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 	{
 	    	cin>>a[i];
	}
	for(int s=1;s<=n;s++){
		num=n;
     	nun=1;
 		b[1]=a[1];
 		l=s-1;
	    while(num!=0)
	    {
	    	l++;
		for(int i=1;i<=nun;i++){
			if(b[i]==a[l])
			{
				for(int j=i;j<=nun;j++)
				{
					b[j]=0;
				}
				nun=i;
				b[i]=a[l];
				break;
			}
			else
			{
				nun+=1;
				b[nun]=a[l];
			}
		}
		num-=1;
    	}
 	    for(int j=1;j<=m;j++)
     	for(int i=1;i<=nun;i++)
		if(b[i]==j)
		{
		    z[j]++;
		    continue;
		}
    }
    for(int i=1;i<=m;i++)
    {
    	cout<<z[i]<<' ';
	}
    return 0;  	
} 
