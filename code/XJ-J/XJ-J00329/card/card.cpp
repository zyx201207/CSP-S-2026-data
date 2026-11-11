#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long a[N],c[N],p[N];
int b[N];
int r=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int f=1;f<=n;f++)
	{
		for(int i=f;i<=n;i++)
	    {
	   	    int k=p[i];
	   	    a[k]++;
		    if(a[k]>=2)
		    {
		    	int y=r;
			    for(int j=y;j>=1;j--)
			    {
				    if(b[j]==k)
				    {
					    break;
				    }
				    else{
					    r--;
					    a[b[j]]--;
				    }
			    }
			    r--;
			    a[k]--;
		    }
		    r++;
		    b[r]=k;
	    }
	    for(int j=r;j>=1;j--)
	    {
	    	c[b[j]]++;
	    	r--;
	    	a[b[j]]--;
	    }
    }
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}