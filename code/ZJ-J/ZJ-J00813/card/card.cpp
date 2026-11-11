#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],lst[N],cur[N],cnt[N],ans[N];
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(register int i=1;i<=n;++i)cin>>a[i];
	for(register int i=n;i;--i){
		lst[i]=cur[a[i]];
		cur[a[i]]=i;
	}
	for(register int i=1;i<=n;++i){
		++cnt[i];
		if(lst[i]!=0)cnt[lst[i]]+=cnt[i];
		else{
			ans[a[i]]+=cnt[i];
			cnt[i+1]+=cnt[i];
		}
	}
	for(register int i=1;i<m;++i)cout<<ans[i]<<' ';
	cout<<ans[m];
	return 0;
}