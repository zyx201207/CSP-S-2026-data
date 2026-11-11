#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];
long long diff[500005];
long long pre[500005];

inline bool check(int M, int i){
	return pre[i]-(a[i]-a[M-1])*(M-1)-pre[M-1]<=m;
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%lld", &a[i]);
    }
    stable_sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
    	diff[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+diff[i]*(i-1);
	}
	int ans=0;
    for(int i=1;i<=n;i++){
    	int L=0,R=i+1;
    	while(L+1<R){
    		int M=(L+R)>>1;
    		if (check(M, i)){
    			R=M;
			} else{
				L=M; 
			}
		}
		ans=max(ans, i-L);
	}
	printf("%d\n", ans);
}