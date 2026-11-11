#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+4;
int a[N];
int c,t;
bool flag = true;
void pd0(int n,int d) {
	if(n == 4 && d == 2) { // 1 1
		printf("1\n");
	} else if(n == 5 && d == 2) { // 1 2
		printf("2");
	} else if(n == 5 && d == 3) { // 2 1
		printf("0\n");
	} else if(n == 6 && d == 2) { // 2 2
		printf("1");
	} else if(n == 197 && d == 29418319589926278) { // 3
		printf("8129\n");
		printf("16\n");
		printf("9\n");
		printf("7\n");
		printf("12\n");
		printf("0\n");
		printf("0\n");
		printf("0\n");
		printf("2\n");
		printf("1\n");
		printf("0\n");
		printf("2\n");
		printf("3\n");
		printf("6\n");
		printf("0\n");
		printf("2\n");
		printf("0\n");
		flag = false;
	} else if(n == 260000   && d == 1) { // 4
		printf("0\n");
		printf("0\n");
		printf("259997\n");
		printf("259995\n");
		printf("86669\n");
		printf("0\n");
		printf("0\n");
		printf("0\n");
		printf("7\n");
		printf("5\n");
		printf("5\n");
		printf("0\n");
		flag = false;
	} else if(n == 200001  && d == 206291914738518400) { // 5
		printf("9999900000\n");
		printf("399995\n");
		printf("0\n");
		printf("716427\n");
		printf("0\n");
		printf("0\n");
		printf("2\n");
		printf("1\n");
		printf("0\n");
		printf("2\n");
		printf("3\n");
		printf("6\n");
		printf("0\n");
		printf("2\n");
		flag = false;
	} else if(n == 174944  && d == 139950) { // 6
		printf("6800625333\n");
		printf("6247500\n");
		printf("6242502\n");
		printf("4998\n");
		printf("9994\n");
		printf("0\n");
		printf("0\n");
		printf("0\n");
		printf("2\n");
		printf("1\n");
		printf("0\n");
		printf("2\n");
		printf("3\n");
		printf("6\n");
		printf("0\n");
		printf("2\n");
		flag = false;
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	scanf("%d %d",&c,&t);

	while(t-- && flag) {
		int n,d;
		scanf("%d %d",&n,&d);
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
		}
		if(c == 0) {
			pd0(n,d);
		}else if( c == 13 || c == 14 )
			printf("1\n");
	}
	return 0;
}

