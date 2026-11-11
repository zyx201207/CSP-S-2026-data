#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int card[N];
int ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>card[i];
	for(int i=n;i>=1;i--)
	{
		int l=1,r=i;
		while(l<r)
		{
			l++;
			if(card[l]==card[r] && card[l]!=-1)
			{
				for(int j=l;j<r;j++)
				{
					card[j]=-1;
				}
			}
		}
		for(int k=1;k<=m;k++) ans[card[k]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i];
}
