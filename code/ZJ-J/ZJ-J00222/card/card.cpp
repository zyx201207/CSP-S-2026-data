#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n,m,a[N],vis[N],ans[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int b[N] = {0},j = i,cnt = 1;
		memset(vis,0,sizeof vis);
		while(j <= n){
			if(!vis[a[j]]){
				vis[a[j]] = 1;
				b[cnt++] = a[j];
			}else{
				int l = 0;
				for(int k = 1;k <= cnt-1;k++){
					if(a[k] == a[j]){
						l = k;
						continue ;
					}
					vis[a[k]] = 0;
				}
				for(int k = 1;k <= (cnt-l);k++){
					b[k] = b[k+l-1];
				}
				cnt = l+1;
			}
			j++;
		}
		for(int k = 1;k <= cnt-1;k++){
			ans[b[k]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
