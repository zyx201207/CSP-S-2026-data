#include<bits/stdc++.h>
using namespace std;

int c, T;

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    srand(time(NULL));
	scanf("%d%d", &c, &T);
	while (T--) {
		printf("%d\n", rand() % 188 + 1);//qwq 
	}
    return 0;
}
