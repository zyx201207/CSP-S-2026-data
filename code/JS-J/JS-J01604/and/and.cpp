#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N];
bool flag[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,res = 0; scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 29;i >= 0;i--){
		int cnt = 0;
		for(int j = 1;j <= n;j++) if(!flag[j]) cnt += a[j] >> i & 1;
		if(cnt < m) continue;
		res += 1 << i;
		for(int j = 1;j <= n;j++) if(~a[j] >> i & 1) flag[j] = 1;
	}
	printf("%d\n",res);
	return 0;
}
