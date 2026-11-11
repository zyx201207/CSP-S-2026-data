#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],vis[300005],ans[300005],e=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=e;
				e++;
			}else{
				int t=vis[a[j]];
				for(int k=1;k<=m;k++){
					if(vis[k]>=t){
						vis[k]=0;
						e--;
					}
				}
				vis[a[j]]=e;
				e++;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]>0){
				ans[j]++;
			}
			//cout<<vis[j]<<' ';
		}
		//cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

