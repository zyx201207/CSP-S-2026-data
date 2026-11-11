#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int d[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],d[a[i]]=i;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)ans[a[j]]++,j=d[a[j]];
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
