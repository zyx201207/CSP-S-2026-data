#include<bits/stdc++.h>
using namespace std;
int a[555555],vis[355555],n,m,s;
bool bo[355555];
map<int,int> ma;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(s != a[i])
		{
			ma[a[i]]++;
			s = a[i];
		}
		
	}
	for(int i = 1;i <=n;i++)
	{
		memset(bo,0,sizeof(bo));
		for(int j = n;j >= i;j--)
		{
			if(bo[a[j]] == 0)
			{
				vis[a[j]]++;
				bo[a[j]] = 1;
			}
			if(ma[a[j]] > 1)
			{	
				break;
			} 
		}
		for(int j = i;j <= n;j++)
		{
			if(bo[a[j]] == 0)
			{
				vis[a[j]]++;
				bo[a[j]] = 1;
			}
			if(ma[a[j]] > 1)
			{	
				break;
			} 
		}
		if(a[i+1] != a[i])ma[a[i]]--;
	}
	for(int i = 1;i <= m;i++)
	{
		cout << vis[i] << " ";
	}
	return 0;
 } 
