#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],ans[300100],last[300100],cnt[300100],vis[300100];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
		cnt[a[i]]++;
	}
	
	for(int i=1;i<=n;i++){
		if(vis[a[i]])continue;
		for(int j=i;j<=n;){
			ans[a[j]]+=cnt[i];
			j=last[a[j]]+1;
		}
		vis[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
