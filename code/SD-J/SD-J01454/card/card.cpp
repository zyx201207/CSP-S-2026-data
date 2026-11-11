#include <bits/stdc++.h>
using namespace std;
struct node{
	bool f;
	int id;
}vis[300005];
int a[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(vis[a[j]].f)
				for(int l=vis[a[j]].id;l<j;l++) vis[a[l]].f=0;
			vis[a[j]].f=1,vis[a[j]].id=j;
		}
		for(int j=1;j<=m;j++) if(vis[j].f) cnt[j]++,vis[j].f=0;
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	return 0;
} 
