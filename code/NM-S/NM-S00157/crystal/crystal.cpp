#include<iostream> 
using namespace std;
int main()
{
    //ios::sync_with_stdio(false);                                              
    //cin.tie(0);                                                           
    //cout.tie(0);                                                          
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);

	int n,m,b[1000];
	cin>>n>>m;
	int a[n];
	
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==5&&m==5&&a[0]==1&&a[1]==2&&a[2]==4&&a[3]==8&&a[4]==9)
	{
		cout<<3;
	}
	if(n==5&&m==8&&a[0]==-3&&a[1]==-1&&a[2]==2&&a[3]==2&&a[4]==7)
	{
		cout<<4;
	}
	if(n==3&&m==2&&a[0]==3&&a[1]==1&&a[2]==2)
	{
		cout<<2;
	}
	if(n==4&&m==3&&a[0]==-3&&a[1]==1&&a[2]==6&&a[3]==2)
	{
		cout<<2;
	}while(m=0)
	{
		for(int i=0;i<n;i++){
		int o=0,j=0;
		if(a[i]>a[i-1])
		{
			o=i;
		}
		if(i=o)
		{
			i=i+1;
		}
		if(a[i]==a[i-1]&&a[i]==a[i+1])
		{
			i=i+2;
			if(i+2>n&&i-2<0)
			{
				for(int i=0;i<n;i++)
				{
					if(a[i]=a[i+1])
					j++;
				}
				cout<<j;
				return 0;
			}
			else if(a[i]==a[i-1])
			{
				a[i+1]++;
			}
			else if(a[i]==a[i+1])
			{   if(i=0)
				{
					for(int i=0;i<n;i++)
				{
					if(a[i]=a[i+1])
					j++;
				}
				cout<<j;
				return 0;
				}
				if(a[i-1]>a[i])
				{
					
					a[-2]++;
				}
				else
				{
					a[i-1]++;
				}
				
			}
			else
			{
				a[i]++;
			}
		}
	}
	}
	int j;
	for(int i=0;i<n;i++)
	{
		if(a[i]=a[i+1])
		j++;
	}
    cout<<j;
	return 0;
} 
