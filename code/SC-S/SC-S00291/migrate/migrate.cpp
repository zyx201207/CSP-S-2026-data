#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int c = 0;
int t = 0;
ll n,d;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	vector <ll> outputlist;
	cin >> c >> t;
	for (int i = 0;i < t;i++)
	{
		cin >> n >> d;
		ll ilist[n] = {};
		for (int h = 0;h < n;h++)
		{
			cin >> ilist[h];
		}
		
		ll addition = 0;
		int rest = addition%d;
		
		ll deltalist[n-1] = {};
		for (int f = 0;f < n-1;f++)
		{
			ll delta = ilist[f+1]-ilist[f];
			delta = n - delta;
			if (delta >= 0)
			{
				deltalist[f] = delta;
			}
			else
			{
				break;
			}
		}
		
		ll output = 0;
		for (int g = 0;g < n;g++)
		{
			addition = 0;
			for (int f = 0;f < g+1;f++)
			{
				addition += ilist[f];
			}
			rest = addition%d;
			
			ll listprivity[g] = {};
			for (int j = 1;j < g;j++)
			{
				if (rest == listprivity[0] + listprivity[j])
				{
					output++;
				}
			}
		}
		outputlist.push_back(output);
	}
	for (int n = 0;n < outputlist.size();n++)
	{
		cout << outputlist[n] << endl;
	}
}