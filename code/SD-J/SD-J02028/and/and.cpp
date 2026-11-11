#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N];
ll maxx,ans,ls[N],ls_cnt;
int n,m;
void dfs(int now,ll annd,int cnt){
	if(cnt==m){
		ans=max(ans,annd);
		return;
	}
	if(now==n+1){
		return;
	}
	dfs(now+1,annd,cnt);
	if(cnt<=m){
		dfs(now+1,annd&a[now],cnt+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx<<endl;
		return 0;
	}
	ls_cnt=1;
	dfs(1,1073741823,0);
	cout<<ans<<endl;
	return 0;
}
