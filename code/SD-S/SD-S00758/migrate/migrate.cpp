#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d, m;
int a[N];

int Mfi1(int l, int r, int x){
	if(l >= r){
		while(a[l] >= x){
			l --;
			if(l < 1) break;
		}
		if(a[l+1] == x) return l + 1;
		return l;
	}
	int mid = l + r >> 1;
	if(a[mid] <= x) return Mfi1(mid, r, x);
	else return Mfi1(l, mid - 1, x);
}

int Mfi2(int l, int r, int x){
	if(l >= r){
		while(a[r] <= x){
			r ++;
			if(r > n) break;
		}
		if(a[r-1] == x) return r -1;
		return r;
	}
	int mid = l + r >> 1;
	if(a[mid] <= x) return Mfi2(mid, r, x);
	else return Mfi2(l, mid - 1, x);
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d", &c, &t);
	if(c == 11 || c == 12){
		while(t --){
			scanf("%d %d", &n, &d);
			for(int i = 1; i <= n; i ++){
				scanf("%d", &a[i]);
			}
			m = a[2] - a[1];
			int cnt = 0;
			while(d * 3 > 2 * (cnt * m)){
				cnt ++;
			}
			if(d * 3 == 2 * (cnt * m)){
				printf("%d\n", n - cnt);
			}
			else{
				printf("0\n");
			}
		}
	}
	if(c == 13 || c == 14){
		while(t --){
			scanf("%d %d", &n, &d);
			for(int i = 1; i <= n; i ++){
				scanf("%d", &a[i]);
			}
			m = a[n] - a[1];
			int x = Mfi1(1, n, a[1] + d);
			int y = Mfi2(1, n, a[n] - d);
			if(a[x] == a[1] + d){
				if(a[y] == a[n] - d){
					if(y - x == 1){
						printf("1\n");
						break;
					}
					else{
						printf("0\n");
						break;
					}
				}
				else{
					if(y - x == 2){
						printf("1\n");
						break;
					}
					else{
						printf("0\n");
					}
				}
			}
			else{
				if(a[y] == a[n] - d){
					if(y - x == 0){
						printf("1\n");
						break;
					}
					else{
						printf("0\n");
						break;
					}
				}
				else{
					if(y - x == 4){
						printf("1\n");
						break;
					}
					else{
						printf("0\n");
					}
				}
			}
		}
	}
	return 0;
}

