#include<bits/stdc++.h>
#define N 200005
typedef long long ll;
using namespace std;

int n,m;
int a[N][40];
int cnt[40];
int u[N] = {0};
ll ans;

void init(int x,int i){
	int p = x;
	int pos = 1;
	while(p){
		cnt[pos] += (p & 1);
		a[i][pos] += (p & 1);
		p >>= 1;
		pos++;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; i++){
		int x;
		scanf("%d",&x);
		init(x,i);
	}
	int flag = 0;
	for(int i = 31 ; i >= 1 ; i--){
		if(cnt[i] >= m){
			flag = i;
			break;
		}
	}
	for(int i = flag ; i >= 1 ; i--){
		if(cnt[i] < m) break;
		ans += 1 << (i - 1);
		for(int j = 1 ; j <= n ; j++){
			if(a[j][i] || u[j]) continue;
			u[j] = 1;
			for(int k = 1 ; k <= 30 ; k++){
				cnt[k] -= a[j][k];
			}
		}
	}
	printf("%lld",ans);

	return 0;
}
