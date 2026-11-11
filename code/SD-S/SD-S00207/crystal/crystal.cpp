#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const int N = 5e5+10;
const int MOD =998244353;
const int INF = 0x3F3F3F3F;
/*====================*/
int n;ll m;
ll a[N];
/*====================*/
void Solve(void){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1;ll sum=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		sum+=(i-l)*(a[i]-a[i-1]);
		//cout<<sum<<' ';
		int res=i-l+1;
		while(l<i&&sum>m){
			sum-=a[i]-a[l];
			--res;++l;
		}ans=max(ans,res);
	}cout<<ans<<'\n';
}
/*====================*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}
/*
有哪些优秀的百合同人作品？ 
*/
