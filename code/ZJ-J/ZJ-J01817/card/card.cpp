#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define M 300005
int n,m,a[N],b[M],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[a[i]]=i+1;
	}for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j=b[a[j]])
			++ans[a[j]];
	for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
	return 0;
}
