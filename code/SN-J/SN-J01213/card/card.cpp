#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N];
int cnt[M],cnt2[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(cnt2,0,sizeof(cnt2));
		vector<int> ve;
		ve.clear();
		for(int j=i;j<=n;j++)
		{
			ve.push_back(a[j]);
			cnt2[a[j]]++;
			if(cnt2[a[j]]==2)
			{
				int f=2,k=0;
				for(auto it:ve)
				{
					k++;
					if(it==a[j] && f==2)
					{
						cnt2[a[j]]--;
						ve[k]=0;
						f=1;
					} 
					else if(it==a[j] && f==1)
					{
						cnt2[a[j]]--;
						ve[k]=0;
						break;
					} 
					else if(f==1)
					{
						cnt2[it]--;
						ve[k]=0;
					}
				}
			}
		}
		for(auto it:ve)
		{
			if(it!=0)
			{
				cnt[it]++;
			}
		}
	} 
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
