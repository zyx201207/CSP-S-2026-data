#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[500005],fa[500005],vis[300005],cnt[300005],sa[500005],dp[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]]==0){
			vis[a[i]]=i;
		}
		else{
			fa[i]=vis[a[i]];
			sa[vis[a[i]]]=i;
			vis[a[i]]=i;
			
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(sa[j]!=0){
				j=sa[j]-1;
			}
			else{
				cnt[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}