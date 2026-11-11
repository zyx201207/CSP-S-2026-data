#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans=0;
long long a[200005];
long long b[35];
bool used[200005];
long long P[200005];
int k=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int l=a[i];
		int p=0;
		while(l)
		{
			if(l%2==1)
			{
				b[p]++;
			}
			l/=2;
			p++;
		}
		p--;
		if(p>k)k=p;
		used[i]=true;
		P[i]=p;
	}
	for(int i=k;i>=0;i--)
	{
		if(b[i]<m) continue;
		for(int j=1;j<=n;j++)
		{
			if((a[j]&(1<<i))==0&&used[j]==true)
			{
				used[j]=false;
				for(int x=0;x<=i;x++)
				{
					if((a[j]&(1<<x))!=0)
					{
						b[x]--;
					}
				}
			}
		}
		ans|=(1<<i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
