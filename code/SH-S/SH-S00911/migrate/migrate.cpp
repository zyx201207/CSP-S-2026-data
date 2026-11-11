#include <iostream>
using namespace std;
int c,t;
int a[2000000+10];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--) {
		int n,d;
		int ans=0;
		cin >> n >> d;
		for (int i=1;i<=n;i++) {
			cin >> a[i];
		}
		int cha=a[2]-a[1];
		int x=d/cha;
		cout << n-(x*2-1) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
