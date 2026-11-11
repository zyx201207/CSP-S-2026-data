#include<bits/stdc++.h>
using namespace std;
int s[10010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	int h=0;
	int p=0; 
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		h+=s[i];
    }
	p=h/n;
	
	sort(s,s+n+1);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
	   	  if(s[i]<p)
	   	  {
	   	  	 s[i]+=1;
	   	  	 m--;
	   	  	 if(s[i]==p)
	   	  	 {
	   	  	 	sum+=1;
				  }	   
		  } 
        }
	    if(s[i]==p)
	    {
	    	sum+=1;
		}
    }
	cout<<sum<<"\n";
	return 0;
}