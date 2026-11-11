#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mx,sum,ans,fl;
int a[200005];
int vis[200005];
bool cmp(int p,int q){
	return p>q;
}
void dfs(int step,int num){
	if(step==m+1){
		ans=max(ans,num);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		if(step==1) dfs(step+1,a[i]);
		else dfs(step+1,num&a[i]);
		vis[i]=0;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(i==1) sum=a[i];
		else sum=(sum&a[i]);
		if(i!=1&&a[i]-a[i-1]!=1) fl=1;
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		} 
		cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}

