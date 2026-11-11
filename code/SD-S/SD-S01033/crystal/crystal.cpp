#include<bits/stdc++.h>
using namespace std;
#define int long long
/*====================*/
const int N=5e5+10;
const int M=1e5+10;
/*====================*/
const int INF=0x3f3f3f3f;
const int MOD=998244353;
/*====================*/
long long n,m,a[N],b[N];
bool check(long long x,long long y){
	long long xx=b[y]-b[x-1],yy=a[y]*(y-x+1);
	return yy-xx<=m;
}
/*====================*/
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)/2;
			if(check(mid,i))r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}
/*====================*/
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	int T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}


