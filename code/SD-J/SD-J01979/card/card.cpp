#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[300005],ta[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int cnt = 0;
		memset(sum,-1,sizeof sum);
		memset(ta,0,sizeof ta);
		for(int j = i;j <= n;j++){
			if(sum[a[j]] == -1){
				ta[++cnt] = a[j];
				sum[a[j]] = cnt;
			}
			else{
				for(int k = sum[a[j]];k <= cnt;k++){
					ta[k] = 0;
				}
				cnt = sum[a[j]]-1;
				ta[++cnt] = a[j];
				sum[a[j]] = cnt;
			}
		}
		for(int j = 1;j <= cnt;j++){
			ans[ta[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
