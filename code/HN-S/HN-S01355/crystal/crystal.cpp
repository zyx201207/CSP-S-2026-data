#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e6; 
int a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,f=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int j=1;j<=n;j++)
		{
			int sum=a[j];
			for(int k=j+1;k<=n;k++)
			{
				sum+=a[k];
				if((sum+m)%(k+1-j)==0)	
					if((sum+m)/(k+1-j)>=a[k]) 
						if((k+1-j)>=f)
							f=k+1-j;
			}
		}
	cout<<f;
 } 
