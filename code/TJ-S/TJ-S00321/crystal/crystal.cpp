#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],c[500005],cnt,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);                                                                                       
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		c[i]=a[i]-a[i-1];
	}
	int d=0;
	for(int i=1;i<=n;i++)
	{
		long long b=0,j=0,k=i;
		cnt=0;
		while(true)
		{
			j++;
			k++;
			b+=j*c[k];
			if(k>n) break;
			if(b<m) cnt++;
			else if(b==m)
			{
				cnt++;
				break;	
			} 
			else break;                                                                        
		}
		while(a[k+1]==a[k] && k<n)
		{
			k++;
			cnt++;
		}
		ans=max(ans,cnt+1);
	} 
	cout<<ans;
	return 0;
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
