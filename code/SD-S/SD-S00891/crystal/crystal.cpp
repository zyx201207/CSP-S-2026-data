#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int inf=LLONG_MAX;
const int maxn=5e5+5;
int a[maxn];
int pre[maxn];
int n,m;
int check(int now,int i){
	int cnt=pre[i]-pre[now-1];
	int num=(i-now+1)*a[i]-cnt;
	if(num<=m){
		return 1;
	}else{
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

