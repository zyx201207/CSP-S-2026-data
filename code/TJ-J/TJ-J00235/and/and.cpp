#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,n;
	cin >> n >> m;
	int a[10005];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
    }
    int maxn = -1;
    for(int i = 1;i <= n;i++){
    	if(a[i] == 1) maxn = a[i];
    	maxn = max(maxn,a[i]&a[i-1]);
	}
	cout << maxn;
	return 0;
}
