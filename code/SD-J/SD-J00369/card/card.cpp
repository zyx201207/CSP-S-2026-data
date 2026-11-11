#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
typedef long long L;
vector<int> a(N);
L ocnt[M],mcnt[M];
int m,n;
bool f=true;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=i;j--)
		{
			memset(ocnt,0,sizeof(ocnt)); 
			ocnt[a[j]]++;
			mcnt[a[j]]++;
			if(ocnt[a[j]]==2)
			{
				for(int k=a.size()-1;a[k]!=a[j];k--)
				{
					ocnt[a[k]]--; 
					mcnt[a[j]]--;
				}
				ocnt[a[j]]--; 
				mcnt[a[j]]--;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<mcnt[i]<<" ";
	}
	return 0;
}

