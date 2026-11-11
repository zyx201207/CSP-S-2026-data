#include<bits/stdc++.h>
using namespace std;
int pre[300005],lst[300005],cnt[300005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		pre[a[i]]=i;
		if(!lst[a[i]])lst[a[i]]=i;
		int x=i;
		while(x<=n){
			cnt[a[x]]++;
			x=lst[a[x]]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
