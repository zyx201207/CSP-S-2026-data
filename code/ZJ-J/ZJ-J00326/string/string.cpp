#include<bits/stdc++.h>
using namespace std;
long long l[1000010];
long long r[1000010];
char s[1000010]={'0'};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0,ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		s[i]=c;
		l[i]=sum;
		r[i]=sum+a-1;
		sum+=a;
	}
	if(1)
	{	
		long long g=r[1]-l[1]+1;
		long long f=r[n]-l[n]+1;
		for(int i=1,j=n;i!=j;)
		{
			if(g>f)
			{
				if(s[i]!=s[j])
				{
					ans+=f;
					g-=f;
					f=r[j-1]-l[j-1]+1;
					j--;
				}
				else
				{
					g-=f;
					f=r[j-1]-l[j-1]+1;
					j--;
				}
			}
			else if(g<f)
			{
				if(s[i]!=s[j])
				{
					ans+=g;
					f-=g;
					g=r[i+1]-l[i+1]+1;
					i++;
				}
				else
				{
					f-=g;
					g=r[i+1]-l[i+1]+1;
					i++;
				}
			}
			else
			{
				if(s[i]!=s[j])
				{
					ans+=f;
					g=r[i+1]-l[i+1]+1;
					f=r[j+1]-l[j+1]+1;
					i++;
					j--;
				}
				else
				{
					g=r[i+1]-l[i+1]+1;
					f=r[j+1]-l[j+1]+1;
					i++;
					j--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}