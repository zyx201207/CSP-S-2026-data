#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans;
void dfs(ll cnt,ll ccnt,ll mm){
	if(cnt>n){
		if(mm==m) ans=max(ans,ccnt);
		return;
	}
	if(mm<m) dfs(cnt+1,(mm?ccnt:a[cnt])&a[cnt],mm+1);
	if(n-cnt+mm>=m) dfs(cnt+1,ccnt,mm);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
//luogu_liuyuxiaozaizai

