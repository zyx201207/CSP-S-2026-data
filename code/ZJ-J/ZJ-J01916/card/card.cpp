//OK
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],cnt[M],nxt[N],pre[N],lst[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=n;i>=1;--i){
		if(!lst[a[i]])lst[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		int u=i;
		while(u<=n){
			//cout<<a[u]<<' ';
			++cnt[a[u]];
			if(lst[a[u]]>=u)u=lst[a[u]];
			++u;
		}
		//cout<<'\n';
	}
	for(int i=1;i<=m;++i)cout<<cnt[i]<<' ';
	return 0;
}