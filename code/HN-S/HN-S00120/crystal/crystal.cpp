#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int s[N];
bool check(int len){
	for(int i=len;i<=n;i++) if(a[i]*len-(s[i]-s[i-len])<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
}
/*
Oct31==Dec25?
*/
