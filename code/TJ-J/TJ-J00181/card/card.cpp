#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector <int> v;
map <int,int> mp;
int n,m,a[500005],cnt[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
 	cin >> n >> m;
 	for(int i=1;i<=n;i++)
 	{
 		cin >> a[i];
	}
	for(int k=1;k<=n;k++)
 	{
 		for(int i=k;i<=n;i++)
	 	{
	 		if(mp[a[i]] == 1)
	 		{
	 			while(mp[a[i]] == 1)
	 			{
	 				mp[v[v.size()-1]] = 0;
					v.pop_back();
				}
			}
	 		else
	 		{
	 			mp[a[i]] = 1;
			}
			v.push_back(a[i]);
		}
		for(int i=v.size()-1;i>=0;i--)
	 	{
	 		cnt[v[i]]++;
	 	}
	 	mp.clear();
	 	v.clear();
	}
	for(int i=1;i<=m;i++)
 	{
 		cout << cnt[i] << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
