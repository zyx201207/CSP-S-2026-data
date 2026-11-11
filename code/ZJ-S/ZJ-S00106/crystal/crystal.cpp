#include<bits/stdc++.h> 
#define PII pair<int,int>
#define int long long
using namespace std;
const int N=1e6+5;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
int n,m,a[N],sum[N],ans;
bool check(int x){
	for(int i=x;i<=n;i++){
		if(sum[i]-sum[i-x]+m>=a[i]*x)return 1;
	}
	return 0;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=0,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve(); 
	return 0;
} 
