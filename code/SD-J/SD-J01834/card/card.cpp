#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,flag1=1,ar[500005]={},last[300005]={},cnt[300005]={};
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		last[ar[i]]=i;
		if(ar[i]<ar[i-1]){
			flag1=0;
		}
	}
	if(flag1){
		for(int i=1;i<=n;i++){
			cnt[ar[i]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt[ar[j]]++;
			j=last[ar[j]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
