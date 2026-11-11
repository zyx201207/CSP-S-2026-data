#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],n,m,ans=LLONG_MIN;
void dfs(int now,int cnt,int sum){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=now+1;i<=n;i++)dfs(i,cnt+1,sum&a[i]);
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(m==1) {
		int maxn=LLONG_MIN;
		for(int i=1; i<=n; i++)cin>>a[i],maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;
	} else if(m==n) {
		cin>>a[1];
		int cnt=a[1];
		for(int i=2; i<=n; i++)cin>>a[i],cnt=cnt&a[i];
		cout<<cnt;
		return 0;
	} else if(m==2) {
		int maxn=LLONG_MIN;
		for(int i=1; i<=n; i++)cin>>a[i];
		for(int i=1; i<=n; i++) {
			for(int j=i; j<=n; j++) {
				if(j==i)continue;
				int cnt=a[i]&a[j];
				maxn=max(maxn,cnt);
			}
		}
		cout<<maxn;
		return 0;
	} else if(n<=20) {
		for(int i=1; i<=n; i++)cin>>a[i];
		for(int i=1;i<=n;i++)dfs(1,1,a[i]);
		cout<<ans;
		return 0;
	}else {
		int sum=0,l=0;
		for(int i=1; i<=n; i++){
			cin>>a[i],sum+=a[i];
			if(a[i]!=0)l++;
		}
		if(l<m){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++)dfs(1,1,a[i]);
	}
	return 0;
}
