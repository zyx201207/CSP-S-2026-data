#include <cstdio>
#include <iostream>
using namespace std;

int main (void) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n, a[256];
	char c[256];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		scanf("%c", &c[i]);
	}

	fclose(stdin);
	fclose(stdout);
}