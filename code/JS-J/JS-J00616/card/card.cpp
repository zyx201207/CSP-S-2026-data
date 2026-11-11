#include <iostream>
using namespace std;
int q[500010],p[500010],a[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) scanf("%d",&q[i]);
	for (int i = 1; i <= n; ++i) {
	    int c = 0;
	    for (int t = 1; t <= c; ++t) p[t] = 0;
	    for (int j = i; j <= n; ++j) {
		int l;
		bool f = 0;
	//	cout << l << " ";
		for (int t = 1; t <= c; ++t)
		   if (p[t] == q[j]) {
		//	cout << t << " " << p[t] << "  " << j << " " << q[j] << endl;
			f = 1,l = t;
			break;
		   }
		if (f) {
		    for (int t = l; t <= c; ++t) p[t] = 0;
		    c = l;
		}
		p[++c] = q[j];
	    }
	    for (int j = 1; j <= c; ++j) a[p[j]]++;
	}
	for (int i = 1; i <= m; ++i) printf("%d ",a[i]);
	return 0;
}
