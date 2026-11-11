#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[200010],cnt[200010],f[500010];
bool vis[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				cnt[a[j]]++;
				f[j]=1;
			}
			else{
				cnt[a[j]]++;
				f[j]=1;
				bool flag=0;
				for(int k=i;k<j;k++){
					if(flag){
						if(vis[a[k]]&&f[k]==1){
							cnt[a[k]]--;
							f[k]=0;
						}
						if(cnt[a[k]]==0){
							vis[a[k]]=0;
						}
					}
					if(a[k]==a[j]&&f[k]==1){
						flag=1;
						cnt[a[k]]--;
						f[k]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(f[j]) ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
