#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],dp[N],ans[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		map<int,bool> mp;
		int pos=0;
		for(int j=i;j<=n;++j){
			if(mp[a[j]]==1){
				while(dp[pos]!=a[j]) pos--;
			}else{
				dp[++pos]=a[j];
				mp[a[j]]=1;
			}
		}
		for(int j=1;j<=pos;++j){
			ans[dp[j]]++;
		}
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<' ';
	return 0;
}
