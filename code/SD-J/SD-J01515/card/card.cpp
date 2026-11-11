#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int a[N], d[M], n, m, ans[N], tt = 0, nw[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int j = 1; j <= n; j++)
	{
		for(int i = j; i <= n; i++)
		{
			if(d[a[i]] == 0)
			{
				tt++;
				nw[tt] = a[i];
				d[a[i]]++;
			}
			else if(d[a[i]] == 1)
			{
				while(!(nw[tt] == a[i]) || nw[tt - 1] == a[i] && d[a[i]] == 1)
				{
					--tt;
					d[a[tt+1]]--;
				}
			}
		}
	}
	for(int k = 1; k <= tt; k++) cout << nw[k] << " ";
	return 0;
} 
