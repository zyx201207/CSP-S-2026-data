#include<bits/stdc++.h>
#include<bits/extc++.h>
#define mod 998244353
#define ll long long
#define hsh __gnu_pbds::gp_hash_table 
using namespace std;
ll n,m;
ll a[500005];
// 卧槽这是 S T1 吗 
// 这是 J 难度吧 
// 双指针。 
// tmd 真是 J T1 难度。不演了。 
// 我要报警了。 
// 好的 T1T2T3T4 都做完了。
// 感觉像 J 组的难度。但是退役了一年，只能勉强拿到接近 200pts。
// 不管有没有 1= 都继续下去吧。省赛再见。 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll wac=0; // 目前的贡献，显然一个连续段绝对是最优的。
	int ans=0; 
	for(int i=1,j=2;j<=n;j++){
		ll hbw=a[j]-a[j-1]; // j 增加了 a[j]-a[j-1]，那么整个的贡献增加了 (j-i)*pre
		wac+=(j-i)*hbw;
		while(i<=j&&wac>m){
			wac-=a[j]-a[i]; // 一个节点的贡献是 a[j]-a[i] 
			i++;
		} 
		ans=max(ans,j-i+1);
	}
	cout<<ans;
}
// Crystal Teardrops
