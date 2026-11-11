#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n,m;
ll ans,a[N];
ll st[N][32];
bool vis[N];
void check(){
	long long sum=0;
	bool flag=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			if(flag){
				sum&=a[i];
			}else{
				sum=a[i];
				flag=1;
			}
		}
	}
	ans=max(ans,sum);
}
void dfs(int x,int cnt){
	if(cnt==m){
		check();
		return;
	}else if(x>n||n-x<m-cnt){
		return;
	}
	vis[x]=1;
	dfs(x+1,cnt+1);
	vis[x]=0;
	dfs(x+1,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000)dfs(1,0);
	else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			st[i][0]=a[i];
		}
		for(int j=1;j<=30;j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				st[i][j]=max(st[i][j],st[i][j-1]&st[i+(1<<j)][j-1]);
			}
		}
		int k=log2(m);
		for(int i=1;i+(1<<k)-1<=n;i++)ans=max(ans,st[i][k]);
	}
	cout<<ans;
	return 0;
}
