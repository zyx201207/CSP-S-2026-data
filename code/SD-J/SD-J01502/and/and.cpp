#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m,a[N];
bool vis[N],b[N][32];
long long ans,r;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);r = n;
	for (int i = 1;i <= n;i++){
		vis[i] = 1;
		scanf("%d",&a[i]);
		long long tt = 0,x = a[i];
		while(x){
			if(x % 2 == 1) b[i][tt] = 1;
			tt++,x /= 2;
		}
	}for (int t = 31;t >= 0;t--){
		int cnt = 0;
		for (int i = 1;i <= n;i++)
			if(b[i][t] && vis[i]) cnt++;
		if(cnt >= m){
			ans += pow(2,t);
			for (int i = 1;i <= n;i++){
				if(!b[i][t]){
					if(vis[i]) r--;
					vis[i] = 0;
				}
			}
		}
	}printf("%lld",ans);
	return 0;
}
//4 2
//3 15 12 12
//5 3
//31 3 1 15 7
