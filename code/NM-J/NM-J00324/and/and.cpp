#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200010],vis[200010];
int ans;

void dfs(int x,int sum,int cnt){
	if(cnt>=m){
		if(cnt==m){
			ans=max(ans,sum);
		}
		return ;
	}
	for(int i=x;i<=n;i++){
		vis[i]=1;
		dfs(i,sum&a[i],cnt+1);
		dfs(i,sum,cnt);
		vis[i]=0;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}else if(m==n){
		int sum=a[1];
		for(int i=1;i<=n;i++){
			sum=sum&a[i];
		}
		cout << sum;
		return 0;
	}else if(m==2){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=max(cnt,a[i]&a[j]);
			}
			cout << cnt;
			return 0;
		}
	}
	dfs(1,a[1],1);
	cout << ans;
	return 0;
}
