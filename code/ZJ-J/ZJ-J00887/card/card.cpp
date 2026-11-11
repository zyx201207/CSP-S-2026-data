#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[5005],mp[5005],vis[5005],ans[5005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=n; i++){
		memset(mp,0,sizeof mp);
		memset(vis,0,sizeof vis);
		for(int j=i; j<=n; j++){
			mp[a[j]]++;
			if(mp[a[j]]==2){
				int bh=0;
				for(int k=i; k<j; k++){
					if(a[k]==a[j]&&!vis[k]){
						bh=k;
						break;
					}
				}for(int k=bh; k<j; k++){
					if(vis[k])continue;
					vis[k]=1;
					mp[a[k]]--;
				}
			}
		}for(int i=1; i<=m; i++){
			if(mp[i]>0)ans[i]++;
		}
	}for(int i=1; i<=m; i++)cout<<ans[i]<<" ";
	return 0;
}