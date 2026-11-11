#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=1;k<=n;k++){
		bool vis[200005];
		int mp[200005];
		memset(vis,0,sizeof(vis));
		memset(mp,0,sizeof(mp));
		for(int i=k;i<=n;i++){
			if(mp[a[i]]==0){
				mp[a[i]]=i;
			}
			else{
				for(int j=mp[a[i]];j<i;j++){
					vis[j]=1;
					mp[a[j]]=0;
				}
				mp[a[i]]=i;
			}
		}
		for(int j=k;j<=n;j++){
			if(!vis[j]){
				cnt[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
