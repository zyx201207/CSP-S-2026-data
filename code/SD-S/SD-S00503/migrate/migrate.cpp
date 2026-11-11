#include <bits/stdc++.h>
#define re register
using namespace std;
int ccc,T,n;
long long d;
const int N = 2e6 + 10;
long long a[N];
int last[N];
bool can[N];
int dp[5010][5010];
int dep[105],may[105],vvis[105];
void dfs(int u,int ed,int step){
	if(step == dep[u]){
		if(vvis[u]) may[u] = 0;
		else{
			vvis[u] = 1;
			may[u] = 1;	
		}
		return;
	}
	if(step < dep[u]){
		may[u] = 0;
		vvis[u] = 0; 
		dep[u] = step;
	}
	if(dep[u] == 0) dep[u] = step;
	for (re int i = u + 1;i <= ed && a[u] + d >= a[i];i ++){
		dfs(i,ed,dep[u] + 1);
	}
}

void mian(){
	
	scanf("%d%lld",&n,&d);
	for (re int i = 1;i <= n;i ++){
		scanf("%lld",&a[i]);
		can[i] = 1;
	}
	if(ccc <= 2){
		long long ans = 0;
		for (re int i = 1;i <= n;i ++){
			for (re int j = i + 3;j <= n;j ++){
				dfs(i,j,1);
				bool ok = 0;
			//	cout << i << " " << j << endl;
				for (re int k = i;k <= j;k ++){
				//	cout << k << " : "<< may[k] << "\n";
					if((ok == 0 && may[k] == 1)) ok = 1;
					else if(ok == 1 && may[k] == 1){
						ok = 0;
						break;
					}
					may[k] = 0;
					vvis[k] = 0;
					dep[k] = 0;
				}
				ans += ok;
			}
		}
		//cout << endl;
		printf("%lld\n",ans);
		return;
	}
	int ans = 0;
	for (re int i = 1;i <= n;i ++){
		int l = i,r = n;
		last[i] = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(a[i] + d >= a[mid]){
				last[i] = mid;
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		if(i == 1) continue;
		if(i >= 3 && last[i - 1] == last[i] && last[i - 2] != last[i] && a[i - 2] + d >= a[i]){
			ans ++;
		}
	}
	printf("%d\n",ans);
	
	
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&ccc,&T);
	while(T --){
		mian();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
