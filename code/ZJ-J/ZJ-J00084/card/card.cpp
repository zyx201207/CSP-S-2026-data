#include <bits/stdc++.h>
using namespace std;
int a[500005],tong[300005],paidui[500005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int zongshu=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				zongshu++;
				vis[a[j]]=zongshu;
				paidui[zongshu] = a[j];
			}else{
				for(int i=vis[a[j]]+1;i<=zongshu;i++){
					vis[paidui[i]] = 0;
				}
				zongshu=vis[a[j]];
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]!=0){
				tong[i]++;
			}
		}
		zongshu = 0;
		memset(paidui,0,sizeof(paidui));
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++){
		cout << tong[i] << " ";
	}
	return 0;
}