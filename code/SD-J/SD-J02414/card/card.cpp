#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],alast[300005],cnt[300005],ans[300005],uing[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		alast[a[i]]=i;
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		int t=0;
		for(int j=alast[i];j<=n;j++){
			ans[a[j]]+=cnt[i];
			j=alast[a[j]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
