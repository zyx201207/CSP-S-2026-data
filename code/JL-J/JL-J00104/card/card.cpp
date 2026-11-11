#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],vis[N],vis2[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		for(int j=i;j<=n;j++){
			if(vis2[a[j]]){
				for(int i=vis2[a[j]];i<=j;i++){
					vis2[a[i]]=0;
				}
			}
			vis2[a[j]]=j;
		}
		for(int i=1;i<=m;i++){
			if(vis2[i])ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}