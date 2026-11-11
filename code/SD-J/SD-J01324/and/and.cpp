#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,l=1,sum[N],len,a[N],pre[32],cnt[32],ans;
vector<int>kl[32],nd;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		for(int j=30;j>=0;--j){
			if(a[i]&(1<<j)){
				cnt[j]++;
			}
		}
	}
	for(int j=30;j>=0;--j){
		if(cnt[j]>=m){
			nd.push_back(j);
		}
	}
	for(int i=1;i<=n;++i){
		for(auto t:nd){
			if(a[i]&(1<<t)){
				sum[i]+=(1<<t);
			}
		}
	}
	sort(sum+1,sum+1+n);
	ans=sum[n];
	for(int i=n-1;i>=n-m+1;--i){
		ans=ans&sum[i];
	}
	cout<<ans;
	return 0;
} 

//ºì³È»ÆÂÌ 
