#include <iostream>
using namespace std;
int q[200010],p[200010],ma = 0,n,m;
void dfs(int c,int s) {
    if (c == m) {
    	ma = max(ma,s);
	return;
    }
    for (int i = c; i <= n; ++i) {
    	if (p[i]) continue;
        p[i] = 1;
	dfs(c + 1,s & q[i]);
	p[i] = 0;
    }
    return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) scanf("%d",&q[i]);
	for (int i = 1; i <= n; ++i) {
	    p[i] = 1;
	    dfs(1,q[i]);
	    p[i] = 0;
	}
	cout << ma;
	return 0;
}
