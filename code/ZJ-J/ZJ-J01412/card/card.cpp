#include<bits/stdc++.h>
#define int long long
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,m,a[N],vis[N],ans[N],t[N];
signed main(){
	ioi;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			vis[a[j]]++;
			if(vis[a[j]]==2)for(int k=t[a[j]];k<j;k++)vis[a[k]]--,t[a[k]]=0;
			t[a[j]]=j;
		}
		for(int j=1;j<=m;j++) if(vis[j]>0) ans[j]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
