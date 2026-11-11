#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m,ans = 1;
long long a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		sum[i] = sum[i - 1] + a[i];
	for (int k = 1;k <= n;k++){
//		for (int s = 1;s <= k;s++){
//			printf("%lld ",(k - s) * a[k] - (sum[k - 1] - sum[s - 1]));
//		}puts("");
//printf("%dkai\n",k);
		int l = 1,r = k;
		while(l < r){
			int mid = (l + r) / 2;
			long long t = (k - mid) * a[k] - (sum[k - 1] - sum[mid - 1]);
			if(t < m) r = mid;
			else{
				if(t == m){
					l = mid;break;		
				}else l = mid + 1;
			}
		}if((k - l) * a[k] - (sum[k - 1] - sum[l - 1]) > m) l++;
		ans = max(ans,k - l + 1);
//printf("%dbi\n",k);
	}printf("%d",ans);
	return 0;
}
