#include<bits/stdc++.h>
using namespace std;
string s1,s2;
const int N=2e6+5;
long long int n,m,t[N],a[N],sum,maxn=-2e9;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]!=a[j])
			{	
				sum=0;
				for(int k=1;k<=m-1;k++)
				{
				sum+=a[i]&a[j+k-1];	
				}
				if(maxn<sum)
				{
					maxn=sum;
				}
			}
		}
		
	}
	cout<<maxn;
	return 0;
}