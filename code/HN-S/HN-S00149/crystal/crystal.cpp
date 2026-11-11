#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int nmax=1e6+5;
const int inf=1e18;
int n,m,a[nmax],pre[nmax];
bool check(int mid){
	for(int i=1;i+mid-1<=n;i++){
		int sum=pre[i+mid-1]-pre[i-1];
		if(a[i+mid-1]*mid-sum<=m) return 1;
	}return 0;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1,r=n+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}cout<<l<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int T=1;
	while(T--)
	solve();
	
	return 0;
} 
