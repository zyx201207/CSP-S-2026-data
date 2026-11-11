#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[2000001],w[2000001];
bool ba[2000001],bw[2000001];
string ca,cw;
long long t=0,len=0,ans=0,n;
void add(long long x)
{
	ans+=x;
	return;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for (long long i=0;i<=n-1;i++)//从零开始 
	{
	    cin>>a[i]>>ca[i];
	    w[n-1-i]=a[i];
	    cw[n-1-i]=ca[i];
	}
//	for (int i=0;i<=n-1;i++)
//	  cout<<a[i]<<" "<<ca[i]<<" "<<w[i]<<" "<<cw[i]<<endl;
	long long i=0,j=0,lr=0;//lr为1是a超w   i给w，j给a 
	while (ba[j]!=1&&bw[i]!=1)
	{
		if (t!=0&&lr==1)//a列超了 
		{
			if (t>=w[i])//t更大 
		    {
			    if (ca[j]!=cw[i])
			    {
				  add(w[i]);
			    }
			    t=t-w[i];
				ba[n-1-i]=bw[i]=1;
				lr=1;
				i++;
		    }
		    else//w更大 
		    {
		    	if (ca[j]!=cw[i])
		    	{
				  add(t);
			    }
		    	t=w[i]-t;
				bw[n-j-1]=ba[j]=1;  
				lr=0;
				j++;
			}
		}
		if (t!=0&&lr==0)//w列超了 
		{
			if (t>=a[j])//t更大 
		    {
			    if (cw[i]!=ca[j])
			    {
				  add(a[j]);
			    }
			    t=t-a[j];
				bw[n-1-j]=ba[j]=1;
				lr=0;
				j++;
		    }
		    else//a更大 
		    {
		    	if (cw[i]!=ca[j])
		    	{
				  add(t);
			    }
			    t=a[j]-t;
				ba[n-i-1]=bw[i]=1;  
				lr=1;
				i++;
			}
		}
		if (t==0)
		{
			if (a[j]>=w[i])//a列更大 
		    {
			    if (ca[j]!=cw[i])
			    {
				  add(w[i]);
			    }
			    t=a[j]-w[i];
				ba[n-1-i]=bw[i]=1;
				lr=1;
				i++;
		    }
			else//w列更大 
		    {
			    if (ca[j]!=cw[i])
			    {
				  add(a[j]);
			    }
			    t=w[i]-a[j];
				bw[n-1-j]=ba[j]=1;
				lr=0;
				j++;
		    }		    
		}
	} 
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
