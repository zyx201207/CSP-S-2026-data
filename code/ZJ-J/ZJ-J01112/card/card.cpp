#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[5005],k[500005],ff,fff;
stack<long long>q;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)ff++;
		else fff++;
	}
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	if(m==2)
	{
		if(a[n]==1)
		{
			cout<<n<<" "<<fff<<"\n";
		}
		else
		{
			cout<<ff<<" "<<n<<"\n";
		}
		return 0;
	}
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		for(int j=i;j>=1;j--)
		{
			if(f[a[j]]!=0)
			{
				while(!q.empty())
				{
					long long x=q.top();
					q.pop();
					f[x]--;
					if(x==a[j])
					{
						break;
					}
				}
			}
			q.push(a[j]);
			f[a[j]]++;
		}
		while(!q.empty())
		{
			long long x=q.top();
			q.pop();
			k[x]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<k[i]<<" ";
	}
	return 0; 
 } 
 /*
 3
2 a
2 b
1 c
*/
