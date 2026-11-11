#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],vis[300005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int x=n;
	while(x--){
		for(int i=n-x;i<=n;i++){
			if(!vis[a[i]]) vis[a[i]]=1,b[i]=a[i];
			else{
				for(int j=i-1;j>=1;j--){
					if(b[j]!=a[i]) vis[b[j]]=0,b[j]=0;
					else break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cnt[b[i]]++;
		}
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
