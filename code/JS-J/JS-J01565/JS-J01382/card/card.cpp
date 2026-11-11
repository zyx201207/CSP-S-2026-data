#include<iostream>
#include<bitset>
#define int long long
using namespace std;
int n,m;
int a[500005];
bitset<500005> vis;
int cnt[500005],last[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vis=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				for(int k=last[a[j]];k<=j;k++) vis[a[k]]=0;
				last[a[j]]=0;
			}
			vis[a[j]]=1;
			last[a[j]]=j;
		}
		for(int i=1;i<=m;i++){
			if(vis[i]==1) cnt[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
