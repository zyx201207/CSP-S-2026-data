#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a,maxn = 0;
	for(int i = 1;i <= n;i++)cout << a[i];
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= m;j++)maxn = max(a[i] = a[j],maxn);
	}
	cout << maxn;
	return 0;
}
