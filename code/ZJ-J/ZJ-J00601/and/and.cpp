#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,ans,sum,ma,a[200010],f[200010];
int cf(int x){
	int i,cnt=1;
	for(i=1;i<=x;i++)cnt*=2;
	return cnt;
}
void dfs(int now,int t,int gs){
	if(now>n){
		if(t!=cf(30)-1&&gs==m)ans=max(ans,t);
		return ;
	}
	dfs(now+1,t,gs);
	dfs(now+1,t&a[now],gs+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i],ma=max(ma,a[i]),f[a[i]]++;
	if(m==1){
		for(i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=30;j++)
			if(a[i]==cf(j)-1)sum++;
	if(sum==n){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	if(ma<4){
		if(f[3]>=m)cout<<3;
		else if(f[3]+f[2]>=m)cout<<2;
		else if(f[3]+f[1]>=m)cout<<1;
		else cout<<0;
		return 0;
	}
	dfs(1,cf(30)-1,0);
	cout<<ans;
}