#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],b[1000],r,cnt[1000];
bool vis[1000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=1;
			}
			else{
				bool pd=0;
				int ans=0;
				for(int k=1;k<=r;k++){
					if(b[k]==a[j]){
						pd=1;
					}
					if(pd){
						vis[b[k]]=0;
						ans++;
					}
				}
				r-=ans;
				vis[a[j]]=1;
			}
			b[++r]=a[j];
		}
		for(int i=1;i<=m;i++){
			if(vis[i]){
				cnt[i]++;
			}
		}
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		r=0;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}