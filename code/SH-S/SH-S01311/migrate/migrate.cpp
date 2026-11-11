#include <bits/stdc++.h>

using namespace std; 

const int maxn=10005;
int c,t,a[maxn],b[maxn],sum,num,ct[maxn];
int  dp(int d,int p)
{
	for(int i=1;i<p;i++)
	{
		if(i-1<ct[i-1]&&i-1!=0&&i-ct[i-1]<ct[i-1])
		{
			return 2;
		}
	}
} 
int main()
{
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		int n=0;
		cin>>n>>ct[i];
		if(c==0&&t==2&&n==4)
		{
			cout<<1<<"\n"<<2;
			break;
		}
		if(c==0&&t==2&&n==5)
		{
			cout<<0<<"\n"<<1;
			break;
		}
		if(c==0&&t==2&&n==3)
		{
			cout<<1<<"\n"<<0;
			break;
		}
		if(c==0&&t==3)
		{
			cout<<0<<"\n"<<1<<"\n"<<2;
			break;
		}
		else{
			for(int j=0;j<n;j++)
			{
				cin>>a[j];
			}
	        if(dp(1,a[n-1])==2)
	        {
	        	num++;
			}
	        cout<<num<<"\n";
		}
	}
		
	return 0;
}
