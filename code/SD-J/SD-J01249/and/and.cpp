#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
int sum1=1ll<<35;
int a[200200];
int n,m;
int ans=0ll;
int maxn=0ll;
void dfs(int x,int y,int sum){
	if (y==m){
		ans=max(ans,sum);
		return ;
	}
	if (x>n){
		return ;
	}
	dfs(x+1,y,sum);
	sum=sum&a[x];
	dfs(x+1,y+1,sum);
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	sum1-=1;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n<=20){
		dfs(1,0,sum1);
		cout<<ans;
	}
	else if (n==m){
		ans=sum1;
		for (int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if (m==1){
		for (int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if (m==2){
		for (int i=1ll;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	else {
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	return 0;
}
