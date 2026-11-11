#include<bits/stdc++.h>
using namespace std;
int a[500005],tag[500005],lst[500005],f[500005];
int id[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!id[a[i]]){
			f[i]=1;lst[i]=i+1;
		}
		else lst[i]=id[a[i]];
		tag[i]=1;id[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(f[i])ans[a[i]]+=tag[i];
		tag[lst[i]]+=tag[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
/*
__/\__
\    /
/_  _\
  \/
*/
