#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1;
int n,m,ans,a[N],f1=1,f2=1,st[N][40];
inline void build(){
	for(int i=1;i<=n;i++) st[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)<=n;i++){
			st[i][j]=st[i][j-1]&st[i+(1<<j-1)][j-1];
		}
	}
}
inline int query(int l,int r){
	if(l>r) return 0;
	int k=log2(r-l+1);
	return st[l][k]&st[r-(1<<k)+1][k];
}
inline void dfs(int x,int sum,int cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	if(x==n+1) return ;
	dfs(x+1,sum&a[x],cnt+1);
	dfs(x+1,sum,cnt);
}
inline int popcount(int x){
	if(!x) return 0;
	return (x&1)+popcount(x>>1);
}
inline bool cmp(int a,int b){
	int x=popcount(a);
	int y=popcount(b);
	if(x!=y) return x>y;
	return a>b;
}
inline bool check(int mid){
	int sum=(1ll<<30)-1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if((sum&a[i])>=mid){
			cnt++;
			sum&=a[i];
		}
	}
	return cnt>=m;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,(1ll<<30)-1,0);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) f2=0;
		int k=log2(a[i]+1);
		if((1<<k)!=a[i]) f1=0;
	}
	if(f1){
		sort(a+1,a+n+1,greater<int>());
		ans=a[1];
		for(int i=2;i<=m;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(n<=20000){
		sort(a+1,a+n+1,greater<int>());
		if(m==1) cout<<a[1];
		else if(m==2){
			for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
			cout<<ans;
		}
		else{
			ans=a[1];
			for(int i=2;i<=n;i++) ans&=a[i];
			cout<<ans;
		}
		return 0;
	}
	if(m==n-1){
		build();
		for(int i=1;i<=n;i++){
			if(i==1) ans=max(ans,query(i+1,n));
			ans=max(ans,query(1,i-1)&query(i+1,n));
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int l=0,r=(1ll<<30)-1;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
/*
8 4
5 10 19 27 18 26 37 45
*/
