#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	int n,m;
	cin >> n>>m;
	int a[10001];
	for (int i = 1;i<=n;i++) cin >> a[i];
	int b[10001] = {0};
	for (int i = 1;i<=n;i++){
		for (int j = i;j<=n;j++){
			a[b[i]]++;
		}
	}
	for (int i = 1;i<=m;i++) cout<<b[i]<<" ";
}