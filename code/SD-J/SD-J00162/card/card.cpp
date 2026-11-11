#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
deque<int> q;
int vis[300005];
int ind[300005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				int len=q.size();
				int cnt=0;
				while(cnt<=len-ind[a[j]]){
					vis[q.back()]=0;
					q.pop_back();
					cnt++;
				}
				q.push_back(a[j]);
				ind[a[j]]=q.size();
				vis[a[j]]=1;
			}
			else{
				q.push_back(a[j]);
				vis[a[j]]=1;
				ind[a[j]]=q.size();
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]){
				ans[j]++;
			}
		}
		for(int j=1;j<=m;j++){
			vis[j]=0;
			ind[j]=0;
		}
		while(!q.empty()){
			q.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
