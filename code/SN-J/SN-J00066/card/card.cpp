#include<bits/stdc++.h> 

using namespace std;

int n, m;
int a[500001];
int ans[500001];

int main () 
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
	    cin >> a[i]; 
	for (int i = 1; i <= n; i++) {
		int l = n;
	    for (int j = i; j <= n; j++) 
	    {
	    	for (int k = 1; k <= n; k++)
	    	    if (a[k] == a[j])
	    	       l = l - k + 1;
		}
		for (int j = 1; j <= l;j++)
		    ans[j]++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
