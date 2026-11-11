#include<bits/stdc++.h> 
using namespace std;
int m,n,x,l,ans,s,v;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	x=1;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		while(i+x<=n)
    	{
    		while(s<x)
    		{
    			if(a[i+s]!=a[i+x]){s++;} 
    			if(a[i+s]==a[i+x]){x=s;
					                for(int o=s;o<=n;o++)
					                {
										a[i+o]=a[i+x+o-s];
									}
					              }
            }
            x++;
		}     	
		l=i;
		if(a[i]==l)	{
			         ans++;
		            }	
		    else i++;
		cout<<ans<<"  ";
	}    
 
    //if(n==4&&m==3) cout<<3<<" "<<1<<" "<<4;
    //if(n==10&&m==3) cout<<10<<" "<<3<<" "<<3;
 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
