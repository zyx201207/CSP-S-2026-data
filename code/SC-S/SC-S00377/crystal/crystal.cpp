#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi firstx 
#define se second
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn],ans,pre[maxn];
bool check(int L){
	for(int i=1;i+L-1<=n;i++){
		int l=i,r=i+L-1;
		if(L*a[r]-(pre[r]-pre[l-1])<=m) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=0,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
/*
要保龄了 T_T T_T T_T 

健达好吃！

睡过头了？！ 

14：33 妈妈我会 T1 了！！！

黄？ 
*/