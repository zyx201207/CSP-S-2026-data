#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+7;
int a[maxn],s[maxn];
int n,m;
bool check(int x){
	for(int i=x;i<=n;i++){
		if(((a[i]*x)-(s[i]-s[i-x]))<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
