#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],b[500005],ans[300005];
bool vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		memset(b,0,sizeof b);
		memset(vis,0,sizeof vis);
		int top = 0;
		for(int k = i;k <= n;k++){
			int index = 0;
			for(int j = 1;j <= top;j++){
				if(b[j] == a[k]){
					index = j;
					break;
				}
			}
			if(index){
				for(int j = index;j <= top;j++) b[j] = 0;
				top = index - 1;
			}
			top++;
			b[top] = a[k];
		}
		for(int j = 1;j <= top;j++){
			if(vis[b[j]]) continue;
			vis[b[j]] = 1;
			ans[b[j]]++;
		}
	} 
	for(int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}

