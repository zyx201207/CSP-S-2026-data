#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MaxN=5e5+5;
int n,m;
int a[MaxN];
int pre[MaxN];

bool check(int len){
	for(int i=len;i<=n;i++){
		if(a[i]*len-(pre[i]-pre[i-len])<=m) return true;
	}
	return false;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=0,r=n+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid;
		}
		else r=mid;
	}
	cout<<l<<endl;
	return 0;
}
