#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;
int n,m,a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,cnt=0,res=0;
	for(int r=1;r<=n;r++){
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m){
			cnt-=(a[r]-a[l]);
			l++;
		}
		res=max(res,r-l+1);
	}
	cout<<res;
	return 0;
}
/*
rp++，想去WC/kel
*/