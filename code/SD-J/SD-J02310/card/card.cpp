#include<bits/stdc++.h>
using namespace std;
int n,m,a[300010],st[300010]={1},ans[300010],vis[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(st,-1,sizeof(st));
		memset(vis,0,sizeof(vis));
		st[0]=1;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=min(j,st[0]-1);k++){
				if(st[k]==a[j]){
					st[0]=k;
					break;
				}
			}
			st[st[0]]=a[j];
			st[0]++;
		}
		for(int j=1;j<st[0];j++){
			ans[st[j]]+=1-vis[st[j]];
			vis[st[j]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
