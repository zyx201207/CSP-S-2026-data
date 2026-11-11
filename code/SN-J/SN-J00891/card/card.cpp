#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,m;
int a[N],num[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		vector<int> v;
		for(int j = i;j <= n;j++)
		{
			bool flag=0;
			for(int k = 0;k < v.size();k++)
			{
				if(v[k]==a[j])flag=1;
				if(flag)v[k]=0;
			}
			v.push_back(a[j]);
		}
		for(int j = 0;j< v.size();j++)num[v[j]]++;
	}
	for(int i =1;i <= m;i++)cout << num[i] << " ";
}
