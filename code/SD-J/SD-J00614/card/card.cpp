#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],in_st[N],cnt[N],st[N],tot;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}for(int i=1;i<=n;++i){
		memset(in_st,0,sizeof in_st);
		memset(st,0,sizeof st);
		tot=0;
		for(int j=i;j<=n;++j){
			if(in_st[a[j]]){
				while(tot>=1&&st[tot]!=a[j]) in_st[st[tot]]=0,tot--;
				tot--;
			}
			st[++tot]=a[j];
			in_st[a[j]]=1;
		}for(int j=1;j<=m;++j){
			if(in_st[j])cnt[j]++;
		}
	}for(int i=1;i<=m;++i)
		cout<<cnt[i]<<' ';
	return 0;
}/*10 3
3 1 2 1 3 2 3 1 2 1
*/
