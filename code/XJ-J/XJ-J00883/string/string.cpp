#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,m,n,sum,ans=0,b[200005];
string s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>b[i]>>s[i];
	m=n,k=1,ans=0;
	while(k<m)
	{
		if(s[k]==s[m])
		{
		    sum=min(b[k],b[m]);
		    b[k]-=sum;
		    b[m]-=sum;
		    if(b[k]==0)
		    k++;
		    if(b[m]==0)
		    m--;
	    }
	    else
	    {
	    	sum=min(b[k],b[m]);
	    	b[k]-=sum;
		    b[m]-=sum;
		    ans+=sum;
		    if(b[k]==0)
		    k++;
		    if(b[m]==0)
		    m--;
		}
	}cout<<ans<<endl;
    return 0;	
} 
