#include<bits/stdc++.h>
using namespace std;
int n,m;
int vis[300005],pos[300005],cnt[300005];
struct node{
	int zhi;
}a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].zhi;
	}
	for(int i=n;i>=1;i--){
		pos[a[i].zhi]=i;
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			vis[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j].zhi]){
				for(int i=pos[a[j].zhi];i<=n;i++){
					vis[a[i].zhi]=0;
				}
				vis[a[j].zhi]=1;
				pos[a[j].zhi]=j;
			}else{
				vis[a[j].zhi]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]){
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 


