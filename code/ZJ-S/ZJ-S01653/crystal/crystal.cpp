#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
using namespace std;
const int maxn=500005;
int a[maxn];
int s[maxn];
int n,m;
int l,r;
int ans;
bool check(int x){
	for(int i=x;i<=n;i++){
		int sum=s[i]-s[i-x];
		if(sum+m>=a[i]*x) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	l=1,r=n;
	ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
