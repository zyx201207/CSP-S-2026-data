#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1000010];
int vis[1000010];
int ans;
void dfs(int pos){
	if(pos==n+1){
		int cnt=0,l=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				cnt=a[i];
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]){
				l++;
				cnt&=a[i];
			}
		}
		if(l==m){
			ans=max(ans,cnt);
		}
		return ;
	}
	vis[pos]=1;
	dfs(pos+1);
	vis[pos]=0;
	dfs(pos+1);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					maxn=max(maxn,a[i]&a[j]);
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		int maxn=0,cnt=a[1],c=a[2];
		for(int i=1;i<n;i++){
			cnt&=a[i];
		}
		for(int i=2;i<=n;i++){
			c&=a[i];
		}
		maxn=max({maxn,cnt,c});
		cout<<maxn;
		return 0;
	}
	int f=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			f=1;
		}
	}
	if(f==0){
		int cnt=a[n];
		for(int i=n;i>=n-m+1;i--){
			cnt&=a[i];
		}
		cout<<cnt;
	}else{
		sort(a+1,a+n+1);
		int cnt=a[n];
		for(int i=n;i>=n-m+1;i--){
			cnt&=a[i]; 
		}
		cout<<cnt;
	}
	return 0;
}
