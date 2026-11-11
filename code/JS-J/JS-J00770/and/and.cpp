#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long n,m,a[N],maxn=0,c=1,q,w;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			c=(c&a[i]);
		}
		cout<<c;
		return 0;
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}else if(m==2){
		for(int i=n;i>=1;i--){
			for(int j=1;j<i;j++){
				 q=a[i];w=a[j];
			maxn=max(maxn,q&w);
			
			}   
		}
		cout<<maxn;
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			
			c=1;
			 for(int j=1;j<=n;j++)
			 {
				 if(j==i)break;
				 else
				 {
					 c=(c&a[j]);
				 }
			}	maxn=max(maxn,c); 
		}cout<<maxn;
	}
 	return 0;
}
