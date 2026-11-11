#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],c[500005];
int check(int x){
	for(int i=1;i+x-1<=n;i++){
		int t=a[i+x-1];
		int lwy=c[i+x-1]-c[i-1];
		__int128 slp=(__int128)t*x-lwy;
		if(slp<=(__int128)m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		c[i]=c[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)==1)l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}