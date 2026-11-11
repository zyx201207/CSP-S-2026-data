#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,dp[2000005],a[2000005];
int st[2000005],cnt[2000005],ans;
bool f[5005][5005];
void bfs(int sx){
	for(int i=1;i<=n;i++)cnt[i]=0,st[i]=9e18;
	queue<int>q;
	q.push(sx);
	st[sx]=0;
	while(!q.empty()){
		int tx=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			int jl=abs(a[i]-a[tx]);
			if(jl>m||i==tx)continue;
			if(st[i]==st[tx]+1){
				cnt[i]++;
				if(cnt[i]==2&&!f[i][tx]){
					ans++;
					f[i][tx]=f[tx][i]=1;
				}
				else if(cnt[i]!=2){
					ans--;
					f[i][tx]=f[tx][i]=0;
				}
			}
			else if(st[i]>st[tx]+1){
				st[i]=st[tx]+1;
				cnt[i]=1;
				q.push(i);
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>T>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=5000){
			for(int i=1;i<=n;i++)bfs(i);
			cout<<ans<<"\n";
			ans=0;
		}
		else{
			int len=m/(a[2]-a[1]);
			for(int i=2;i<n;i++)ans+=min(len,n-i);
			cout<<ans<<"\n";
			ans=0;
		} 
	}
	return 0;
}
/*
CSP-S 2026游记

不记得第几年CSP-S了，反正至少3年了，至今CSP-S2=,从未获取过1=

以严肃吓死。

T1严肃思考后发现尺取法(双指针)可以做秒了

T2嘟嘟嘟大思考后直接抛弃大脑放弃思考，暴力获得44pts

*/
