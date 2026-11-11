#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime> 
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	while (q--) cout << rand() % 12;
	return 0;
}
