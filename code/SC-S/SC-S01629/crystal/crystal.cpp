#include<bits/stdc++.h>
#define N 500002
#define ll long long 
using namespace std;
int n,ans;
ll m,sum[N],a[N];
inline bool check(int l,int r){ // 是否可能在 m 步内让区间 l~r 的元素全部归中（货舱选址） 
	ll u=a[r]*(r-l+1)-(sum[r]-sum[l-1]);
	return (u<=m); 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	for(int i=1; i<=n; i++){
		int L=0,R=i-1;
		while(L<R){
			int mid=(L+R+1)>>1;
			if(check(i-mid,i)) L=mid;
			else R=mid-1;
		}
		ans=max(ans,L+1);
	}
	cout<<ans;
	return 0;
}

/*
-128033309
-2567500
*/