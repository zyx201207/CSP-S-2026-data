#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
long long int n,a[N],cnt[N],ans;
string s1;
char s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]!=a[j])
			{
				cnt[a[j]]++;
			}else
			{
				for(int k=j;k<=i;k++)
				{
					cnt[a[k]]--;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
