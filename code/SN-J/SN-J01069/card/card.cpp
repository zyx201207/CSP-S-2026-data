#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		deque<int> dq;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=0){
				while(dq.back()!=a[j]){
				    vis[dq.back()]--;
				    dq.pop_back();
				}
			}else{
			    dq.push_back(a[j]);
			    vis[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++) ans[j]+=vis[j];
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
} 
