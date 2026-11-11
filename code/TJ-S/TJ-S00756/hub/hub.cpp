#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int t;
	cin >> t;
	while (t--) cout << 1 + rand() % 3;
	return 0;
}
