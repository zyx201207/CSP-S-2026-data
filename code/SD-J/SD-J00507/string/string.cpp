#include<bits/stdc++.h>
using namespace std;
long long lg;
long long lgnow;
long strn[200010];
char strm[200010];
long long nn;
char zong [400010];
long long cnt;
long long dif;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>nn;
	for(long i=1;i<=nn;i++)
	{
		cin>>strn[i]>>strm[i];
	}
	for(long i=1;i<=nn;i++)
	{		
		lg+=strn[i];
		for(long j=1;j<=strn[i];j++)
		{
			cnt+=1;
			zong[cnt]=strm[i];
		}
	}

    if(lg%2==0)
    {
    	for(int i=1;i<=lg/2;i++)
    	{
    	    if(zong[i]!=zong[lg-i+1])
    	    {
    	    	dif+=1;
			}
		}
	}
	else
	{
		for(int i=1;i<=(lg+1)/2;i++)
    	{
    	    if(zong[i]!=zong[lg-i+1])
    	    {
    	    	dif+=1;
			}
		}
	}
	cout<<dif;
	return 0;
}
