#include <cstdio>
#include <algorithm>

int a[500005];
int b[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n;i++){
		scanf("%d", &a[i]);
	}
	std::sort(a+1, a+n+1);
	for(int i = 1;i <= n-1;i++){
		b[i] = a[i+1]-a[i];
	}
	int ans = 0;
	int cnt = b[1];
	while(m>=cnt){
		m-=cnt;
		cnt+=b[1];
		ans++;
	}
	
	printf("%d", ans+1);
	
	return 0;
}
