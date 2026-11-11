#include <bits/stdc++.h>
using namespace std;

int n,m,sum;
int a[500010];
 
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	long long cha = m + 1;
	while (cha > m) {
		cha = 0;
		for (int i = 1;i < n;i++) {
			cha += a[n] - a[i];
		} 
		if(cha > m)
			n--;
	}
	printf("%d",n);
	return 0;
} 
