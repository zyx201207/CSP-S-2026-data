#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[501000],s[501000],l,r,mid,maxn;
bool check(int u,int v){
	if(a[v]*(v-u+1)-(s[v]-s[u-1])<=m) return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		l=i;r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			if(check(i,mid)) l=mid;
			else r=mid-1;
		}
		maxn=max(maxn,l-i+1);
//		cout<<i<<' '<<l<<'\n';
	}
	cout<<maxn;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
