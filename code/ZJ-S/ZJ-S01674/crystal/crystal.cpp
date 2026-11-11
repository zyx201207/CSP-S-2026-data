#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int n,m,st[25][N],a[N],s[N],hhr2[N];
inline int get(int l,int r){
	int hhr=hhr2[r-l+1];
	return max(st[hhr][l],st[hhr][r-(1<<hhr)+1]);
}
inline bool check(int len){
	for(int i=1;i+len-1<=n;i++){
		int l=i,r=i+len-1;
		int sum=s[r]-s[l-1];
		int maxx=get(l,r);
		int c=maxx*len-sum;
		if(c<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) hhr2[i]=log2(i);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i],st[0][i]=a[i];
	for(int i=1;i<=20;i++) for(int j=1;j+(1<<i)-1<=n;j++) st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
