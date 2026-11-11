#include<bits/stdc++.h>
using namespace std;
int a[200010];
char s[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n,t=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n/2;i++)
	{
		if(a[i]>a[n+1-i])
		{
			int p=i;
			while(a[i]>0)
			{
				
				if(s[i]!=s[n+1-p])
				{
					if(a[i]<=a[n+1-p])
					{
						int q=a[i];
						a[i]-=a[n+1-p];
						a[n+1-p]-=q;
						t+=q;
					}
					else
					{
						t+=a[n+1-p];
						a[i]-=a[n+1-p];
						p++;
					} 
					
				}
				else
				{
					if(a[i]<=a[n+1-p])
					{
						int q=a[i];
						a[i]-=a[n+1-p];
						a[n+1-p]-=q;
					}
					else 
					{
						a[i]-=a[n+1-p];
						p++;
					}
				}
			}
		}
		else if(a[i]<a[n+1-i])
		{
			int p=i;
			while(a[n+1-i]>0)
			{
				if(s[p]!=s[n+1-i])
				{
					if(a[p]>=a[n+1-i])
					{
						int q=a[n+1-i];
						a[n+1-i]-=a[p];
						a[p]-=q;
						t+=q;
						i=p;
					}
					else 
					{
						t+=a[p];
						a[n+1-i]-=a[p];
						p++;
					}
					
				}
				else
				{
					if(a[p]>=a[n+1-i])
					{
						int q=a[n+1-i];
						a[n+1-i]-=a[p];
						a[p]-=q;
						i=p;
					}
					else 
					{
						a[n+1-i]-=a[p];
						p++;
					}	
				}
			}
		}
		else
		{
			if(s[i]!=s[n+1-i])
				t+=a[i];
		}
	}
	cout<<t;
	return 0;
}

