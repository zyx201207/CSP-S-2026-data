#include<iostream>
using namespace std;
int a[40005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	int m;
	int x[m];
	int cnt=0;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
		
	}
	for(int i=0;i<n;i++)
	{
		int b=0;
		if(a[i]!=x[b]&&x[b]!=x[b-1])
		{
			x[b]=a[i];
			
		}
		b++;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i+1]==a[i])
		{
			for(int j=0;j<a[i=1];j++)
			{
				a[j]=0;
				
			} 
			for(int i=0;i<n;i++)
			{
				if(a[i]==x[i])
				
				cnt++;
			}
		}
	} 
	cout<<cnt;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0; 
 } 
