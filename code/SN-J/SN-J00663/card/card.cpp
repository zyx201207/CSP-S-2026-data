//luoqiyuan xianshitieyizhongxue SN-J00663
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int lst[300005];
int a[500005];
int cnt[300005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int now=i;
		while(now<=n){
			int x=a[now];
			cnt[x]++;
			now=lst[x]+1;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
