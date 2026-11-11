#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],lst[300005],cnt[300005],sum[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
		sum[a[i]]++;
	}
	if(m<=n){
		for(int i=1;i<=m;i++){
			int x=lst[i];
			while(x<=n){
				cnt[a[x]]+=sum[i];
				x=lst[a[x]]+1;
			}
			cnt[a[x]]+=sum[i];
		}
	}
	else{
		for(int i=1;i<=n;i++){
			int x=i;
			while(x<=n){
				cnt[a[x]]++;
				x=lst[a[x]]+1;
			}
			cnt[a[x]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
1 2 3 4 5 6 7 8 9 10
4 3
1 2 1 3
*/
