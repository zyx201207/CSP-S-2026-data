#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn];
int s[maxn];
int ans;
bool check(int l,int r){
	if((r-l)*a[r]-(s[r-1]-s[l-1])<=m){
		return true;
	}else{
		return false;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		int cnt=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				cnt=i-mid+1;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
