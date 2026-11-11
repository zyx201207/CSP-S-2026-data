#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+5;
const int M = 3e5+5;
vector<int> v;
int a[N],b[M],bb[M];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	for(int k = 1; k <= n; k++)
	{
		v.clear();
		memset(b,0,sizeof(b));
		
		for(int i = k; i <= n; i++)
		{
			int t = a[i];
			
			if(b[t])
			{
				int f = 0;
				while(v[f] != t)
					f++;
				
				for(int j = f; j < v.size(); j++)
				{
					b[v[j]]--;
					v[j] = 0;
				}
			}
			
			v.push_back(t);
			b[t]++;
		}
		
		for(int i = 1; i <= m; i++)
			bb[i] += b[i];
	}
	
	for(int i = 1; i <= m; i++)
		cout << bb[i] << ' ';
	
	return 0;
}
