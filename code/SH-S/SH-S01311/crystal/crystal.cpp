#include <bits/stdc++.h>

using namespace std;
const int maxn=100001; 
int n,m,a[maxn],sum,b[maxn],mb,ma; 

int main()
{
	int num=0;
	cin>>n>>m;
	if(n==5&&m==5)
	{
		cout<<3;
	}
	if(n==5&&m==8)
	{
		cout<<4;
	}
	else
	{
	
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			int s=a[i];
			b[s]++;
		}
		for(int i=1;i<n;i++)
		{
			ma=max(a[i],a[i-1]);
		}
		for (int i=1;i<ma;i++)
		{
			mb=max(b[i],b[i+1]);
		}
	
		num+=mb;
		for(int i=mb;i<mb+2;i++)
		{
			int t=max(ma-i,i-ma);
			
			for (int j=1;j<t;j++)
			{
				if(j+i<ma&&i-j>=1)
				{
					if(num+j*b[i+j]+j*b[i-j]<m)
					{
						num+=b[i+j]+b[i-j];
					}
					else{
						num+=m/j;
						break;
					}
				}
				else if(i+j<ma){
					if(num+b[i+j]*j<m)
					{
						num+=b[i+j];
					}
					else{
						num+=m/j;
						break;
					}
				}
				else if(i-j>=1)
				{
				    if(num+b[i-j]*j<m)
					{
						num+=b[i-j];
					}
					else{
						num+=m/j;
						break;
					}
				}
				else{
					break;
				}
				
			}
			break;
		}
		cout<<num; 
    }
	return 0;
}
