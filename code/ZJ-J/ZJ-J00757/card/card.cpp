#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,t,f[N],a[N],c[N],l,i,ans[N],nxt[N],cnt[N];
vector<int> A[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i],cnt[i]=1;
	for(i=n;i>=1;i--){
		if(f[a[i]]) nxt[i]=f[a[i]];
		else f[a[i]]=i;
	}
	for(t=1;t<=n;t++){
		int x=t;
		ans[a[x]]+=(c[a[x]]!=t)*cnt[t];
		c[a[x]]=t;
		while(nxt[x]) x=nxt[x];
		x++;cnt[x]+=cnt[t];
	}
	for(i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
