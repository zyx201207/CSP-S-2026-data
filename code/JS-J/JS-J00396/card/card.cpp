#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+10;
int a[N],vis[N],f[N],cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(vis[j]==1) continue;
			for(int k=j+1;k<=n;k++){
				if(a[k]==a[j]){
					for(int l=j;l<k;l++){
						vis[l]=1;
					}
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(vis[j]==0&&f[a[j]]==0){
				cnt[a[j]]++;
				f[a[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
