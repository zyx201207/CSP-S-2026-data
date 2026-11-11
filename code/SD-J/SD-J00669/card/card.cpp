#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;
const int N=5e5+10;
int a[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		vector<int>v;
		map<int,int>s;
		for(int j=i;j<=n;j++)
		{
			if(s.count(a[j]))
			{
				int bj=0;
				for(int k=0;k<(int)v.size();k++)
				{
					if(k==a[j])
					{
						bj=k;
						break;
					}
				}
				for(int k=(int)v.size()-1;k>=bj;k--)
				{
					s.erase(v[k]);
				}
				bj=v.size()-1-bj;
				while(!bj)
				{
					bj--;
					v.pop_back();
				}
			}
			v.push_back(a[j]);
			s[a[j]]++;
		}
		for(int j=0;j<(int)v.size();j++)
		{
			mp[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<mp[i]<<" ";
	}
	cout<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
