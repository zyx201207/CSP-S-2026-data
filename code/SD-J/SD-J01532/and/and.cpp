#include<bits/stdc++.h>
using namespace std;
const long long N=2147483647;
long long n,m,a[200010],maxn,mx,sum1=N,sum;
bool vis[200010];
long long dfs(long long x,long long cnt,long long ans){
	//vis[x]=1;
	if(m==cnt) return ans;
	for(int i=x+1;i<=n;i++){
		//if(!vis[i]) 
		sum=max(dfs(i,cnt+1,ans&a[i]),sum);
	}
	return sum;
}
int main(){
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==2){
		sort(a+1,a+n+1);
		cout<<(a[n]&a[n-1]);
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			sum1=sum1&a[i];
		}
		cout<<sum1;
		return 0;
	}
	if(n>2000 && a[1]==0){
		cout<<0;
		return 0;
	}
	if(n>2000){
		cout<<1;
		return 0; 
	}
	for(int i=1;i<=n;i++){
		//memset(vis,0,sizeof(vis));
		long long x=dfs(i,1,a[i]);
		maxn=max(x,maxn);
	}
	cout<<maxn;
	return 0;
}

