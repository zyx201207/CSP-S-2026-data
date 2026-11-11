#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 5;
ll a[N];
ll ch[N];
int nums[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt = 0;
	cin>>n>>m;
	for(int i = 1;i <= n;++i)cin>>a[i];
	int ans = -1;
	ch[1] = 0;
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;++i){
		int num = 1;
		while(a[i + 1] == a[i] && i < n){
			++i;++num;
		}
		nums[++cnt] = num;
		ans = max(ans,num);
		ch[cnt + 1] = a[i + 1] - a[i];
	}
	ll ad = 0,pch = 0;
	int po = 0,jl = 1;
	int pre = nums[1];
	for(int i = 2;i <= cnt;++i){
		ad += pre * ch[i];
		pch += ch[i];
		pre += nums[i];
		while(ad > m && ad){
			int js = (ad - m + pch - 1) / pch;
			if(js > nums[jl] - po){
				js -= nums[jl] - po;
				pre -= (nums[jl] - po);
				ad -= pch * (nums[jl] - po);
				po = 0;++jl;
				pch -= ch[jl];
			}else{
				po = js;
				pre -= js;
				ad -= pch * js;
			}
		}
		ans = max(ans,pre);
		
	}
	cout<<ans;
	
	return 0;
}