#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mcx=5e5+5;
int n,m,a[mcx],pre[mcx],lst[mcx],cnt[mcx];
signed main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(pre,-1,sizeof pre);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(lst[a[i]])pre[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		int x=i;
		for(int j=i;j<=n;j++){
			while(pre[j]!=-1)j=pre[j];
			cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" \n"[i==m];
	return 0;
}
