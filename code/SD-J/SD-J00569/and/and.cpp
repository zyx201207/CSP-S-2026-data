#include<bits/stdc++.h>
using namespace std;
int m,n,ans,maxt,a[100005],x,y,s,z;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n-1;i++)
		{
			x=a[i];
			for(int j=i+1;j<=n;j++) 
			{
				y=a[j];
				s=x&y;
				maxt=max(maxt,s);
			}
		}
	}
	if(m==3)
	{
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++) 
				for(int k=1+i+j;k<=n;k++)
				{
					x=a[i];
					y=a[j];
					z=a[k];
					s=x&y&z;
					maxt=max(maxt,s);
				}	
	}
	cout<<maxt;
	return 0;
}
