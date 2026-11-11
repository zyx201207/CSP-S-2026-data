#include<bits/stdc++.h>
using namespace std;

long long n, m, a[500005],tp,al[300005], alp[200005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i< n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i< n; i++)
	{
		tp = i;
		for(int j = i; j<n;j++)
		{
			if(alp[a[j]]==i)
			{
				while(a[tp]!=a[j])
				{
					al[a[tp]]--;
					alp[a[tp]]=-1;
					tp--;
				}
			}
			else
			{
				alp[a[j]]=i;
				al[a[j]]++;
			}
		}
	}
	for(int i = 0; i< m; i++)
	{
		cout << al[i] << ' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
