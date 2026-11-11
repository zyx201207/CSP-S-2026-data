#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],st[300005],f[300005],t,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int i = 1;i <= m;i ++){
			f[i] = 0;
		}
		t = 0;
		for(int j = i;j <= n;j ++){
			if(f[a[j]] == 0) {
				f[a[j]] = j;
				st[++ t] = a[j];
			}
			else{
				t = f[a[j]];
				for(int k = 1;k <= m;k ++){
					f[k] = 0;
				}
				for(int k = 1;k <= t;k ++){
					f[st[k]] = k;
				}
			}
		}
		for(int j = 1;j <= t;j ++){
			ans[st[j]] ++;
		}
	}
	for(int i =  1;i <= m;i ++){
		cout << ans[i] << " ";
	}
	return 0;
}
