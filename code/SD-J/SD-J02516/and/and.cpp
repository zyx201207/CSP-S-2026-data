#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];

int ad(int n,int m)
{
	int c,b;
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int s=maxx;
			maxx=max(maxx,a[i]&a[j]);
			if(s!=maxx)c=i,b=j;
		}	
	}
	m-=2;
	while(m--)
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=c&&i!=b)maxx=max(maxx,a[i]&maxx);
		}
	}
	return maxx;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]; 	
	int s=ad(n,m); 
	cout<<s;
 } 
