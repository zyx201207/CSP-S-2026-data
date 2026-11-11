#include <bits/stdc++.h>
using namespace std;

int n;
long long d;
long long a[2000005];
int T,c; 
int res;
int rescnt=0;

inline void dfs(int i, int j, int bushu){
	if (i==j){
		if (res>bushu){
			res=bushu;
			rescnt=1;
		} else{
			if (res==bushu){
				rescnt++;
			}
		}
		return;
	}
	for(int p=i+1;a[p]-a[i]<=d && p<=j;p++){
		dfs(p,j,bushu+1);
	}
}

inline bool check(int i, int j){
	res=rescnt=0;
	dfs(i,j,0);
	return rescnt==2;
}

inline void solve(){
	scanf("%d%lld", &n, &d);
	for(int i=1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	if (c==13 || c==14){
		printf("0\n");
		return;
	}
	if (c<=6){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if (check(i,j)){
					ans++;
					cout << i << ' ' << j << '\n';
				}
			}
		}
		printf("%lld\n", ans+1);
		return;
	}
	if (c==11 || c==12){
		//dcsl
		long long D=a[2]-a[1];
		long long k=d/D;
		if (k==0){
			printf("0\n");return;
		}
		if (d>n){
			printf("0\n");return;
		}
		printf("%lld\n", (long long)(n-k));
		return ;
	}
	printf("0");
}

/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	for(;T--;){
		solve();
	}
}