#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int pre[N];
int n,m;
bool chk(int x){
	for(int i=1;i<=n-x+1;i++){
		int sum=pre[i+x-1]-pre[i-1];
		if(a[i+x-1]*x-sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]+=a[i],pre[i]+=pre[i-1];
	int l=1,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(chk(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
