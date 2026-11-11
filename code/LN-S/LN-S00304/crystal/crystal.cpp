#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],sum[500010],n,m,ans,k;
bool check(int s,int c){
	int r=a[c]*(c-s)-(sum[c-1]-sum[s-1]);
	if(r>m) return false;
	return true;
}
int erfen(int s,int l,int r){
	if(l==r) return l;
	int mid=(l+r+1)>>1;
	if(!check(s,mid)) return erfen(s,l,mid-1);
	return erfen(s,mid,r);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	ans=max(ans,erfen(i,1,n)-i+1);
	cout<<ans;
	return 0;
}
//vocalT1居然不是贪心
//15:12 T1 AC
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
