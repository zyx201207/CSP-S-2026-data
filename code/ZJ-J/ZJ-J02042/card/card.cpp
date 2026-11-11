#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],ans[500005],n,m,last[500005],cnt[500005];
bool vis[500005];
bitset<5005> f[200005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(vis[a[i]]){
			f[i]=f[last[a[i]]];
			cnt[last[a[i]]]++;
		}
		else{
			cnt[i]++;
			f[i]=f[i+1];
			f[i][a[i]]=1;
			vis[a[i]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]){
			for(int j=1;j<=m;j++){
				ans[j]+=(int)f[i][j]*cnt[i];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
