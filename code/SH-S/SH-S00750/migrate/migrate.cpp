#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 2e6 + 5;
int C, T;
int n;
int ii, jj;
long long d;
long long a[MAXN];
int blkcnt, blk[MAXN];
int prv[MAXN], nxt[MAXN], cprv[MAXN], cnxt[MAXN], lcprv[MAXN], lcnxt[MAXN], slcnxt[MAXN];
int typ;
int len, idx, path[MAXN];
long long cnt;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &C, &T);
	if(C <= 6){
	while(T--){
		cnt = 0;
		scanf("%d%lld", &n, &d);
		for(int i = 1;i <= n;i++){
			scanf("%lld", &a[i]);
		}
		for(int i = 1;i <= n;i++){
			prv[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
			nxt[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
		}
		for(int i = 1;i <= n;i++){
			if(prv[i] == i)blkcnt++;
			blk[i] = blkcnt;
		}
//		for(int i = 1;i <= n;i++){
//			printf("prv[%d]=%d, nxt[%d]=%d, blk[%d]=%d\n", i, prv[i], i, nxt[i], i, blk[i]);
//		}
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(blk[i] != blk[j])continue;
				len = 0;
				typ = 0;
				ii = i;
				jj = j;
				while(nxt[ii] < j){
					ii = nxt[ii];
					path[++len] = ii;
				}
				idx = len;
				while(prv[jj] > i){
					jj = prv[jj];
					if(jj != path[idx]){
						if(typ){
							typ = 2;
							break;
						}else if(path[idx] - jj != 1){
							typ = 2;
							break;
						}else typ = 1;
					}
					idx--;
				}
				if(typ == 1)cnt++;
			}
		}
		printf("%lld\n", cnt);
	}
	}else{
	while(T--){
		cnt = 0;
		scanf("%d%lld", &n, &d);
		for(int i = 1;i <= n;i++){
			scanf("%lld", &a[i]);
		}
		for(int i = 1;i <= n;i++){
			prv[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
			nxt[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
//			printf("prv[%d]=%d, nxt[%d]=%d\n", i, prv[i], i, nxt[i]);
		}
		for(int i = 1;i <= n;i++){
			lcprv[i] = lcnxt[i] = 1;
			if(nxt[prv[i]] == i){
				cprv[i] = prv[i];
				lcprv[i] = lcprv[cprv[i]] + 1;
			}
			if(prv[nxt[i]] == i){
				cnxt[i] = nxt[i];
				lcnxt[i] = lcnxt[cnxt[i]] + 1;
			}
			slcnxt[i] = slcnxt[i - 1] + lcnxt[i];
		}
//		for(int i = 1;i <= n;i++){
//			printf("prv[%d]=%d, nxt[%d]=%d, blk[%d]=%d\n", i, prv[i], i, nxt[i], i, blk[i]);
//		}
		for(int i = 2;i <= n - 2;i++){ // i & i + 1 are relays
			for(int s = prv[i + 1];s >= 1 && nxt[s] == i + 1;s--){ // s is the left diversion point
//				printf("Contribution of pair (%d, %d, %d): ", i, i + 1, s);
//				printf("%lld\n", lcprv[s] * (slcnxt[nxt[i]] - slcnxt[nxt[i - 1]]));
				cnt += lcprv[s] * (slcnxt[nxt[i]] - slcnxt[nxt[i - 1]]);
			}
		}
		printf("%lld\n", cnt);
	}
	}
	return 0;
}
