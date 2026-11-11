#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, cnt[N], a[N], b[N], ans[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		memset(cnt,0 ,sizeof(cnt));
		for(int j = i; j <= n; j ++)
			b[j] = a[j];
		for(int j = i; j <= n; j ++){
			if(cnt[b[j]]!=0){
				int lt = j-1;
				while(lt >= i){
					if(b[lt]==b[j])
						break;
					cnt[b[lt]]--;
					lt--;
				}
			}else
				cnt[b[j]]++;
		}
		for(int j = 1; j <= m;j++)
			ans[j]+=max(0ll,cnt[j]);             
	}
	for(int i = 1;i<=m;i++)
		cout << ans[i] <<' ';
	return 0;
}
