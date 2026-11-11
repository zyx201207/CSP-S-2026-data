#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],nxt[N];map<int,int> mp,ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=n;i++){for(int j=i+1;j<=n;j++){if(a[j]==a[i]){nxt[i]=j;break;}}}
	for(int ro=1;ro<=n;ro++){
		mp.clear();
		for(int i=ro;i<=n;){if(nxt[i]!=0){for(int j=i+1;j<nxt[i];j++){mp[a[j]]=0;}i=nxt[i];}else{mp[a[i]]=1;i++;}}
		for(int i=1;i<=m;i++){if(mp[i]){ans[i]++;}}
	}
	for(int i=1;i<=m;i++){cout<<ans[i]<<" ";}
	return 0;
}