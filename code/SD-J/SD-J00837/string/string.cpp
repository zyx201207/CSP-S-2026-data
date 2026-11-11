#include<bits/stdc++.h>
using namespace std;
char td[100000000] = {0};
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin>>n;
	int q;
	char w;
	int r = 0 , l = -1, nump = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>q>>w;
		int u = l + 1;
		for (int p = 0; p < q; p++)
		{
			td[p + u] = w;
			l = l + 1;
		}
	}
	while (l >= r)
	{
		if(td[r] != td[l])
		{
			nump = nump + 1;	
		}
		r++;
		l--;
	}
	cout<<nump;
	return 0;
}
