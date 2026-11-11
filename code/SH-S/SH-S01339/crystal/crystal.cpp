#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,energy[MAXN],presum[MAXN];
int ans=0;
inline int getsum(int l,int r){
	return presum[r]-presum[l-1];
}
inline bool check(int l,int r){
	int len=r-l+1;
	int need=energy[r]*len-getsum(l,r);
	return need<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>energy[i];
	sort(energy+1,energy+n+1);
	for(int i=1;i<=n;i++) presum[i]=presum[i-1]+energy[i];
	int l=1,r=1;
	for(;l<=n;l++){
		while(r<n && check(l,r+1)) r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
} 
