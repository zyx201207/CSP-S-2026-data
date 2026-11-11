#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int nmax=1e6+5;
const int inf=1e18;
int n,m,a[nmax];
int ans,cnt,cent;
void dfs(int l,int r,int s){
	if(s>ans) return;
	if(l==r){
		if(ans==s) cnt++;
		else cnt=1;
		ans=s;
		return;
	}
	int pos=upper_bound(a+l+1,a+n+1,a[l]+m)-a-1;
	for(int i=l+1;i<=pos;i++)
		dfs(i,r,s+1);
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int kans=0;
	for(int i=4;i<=n;i++){
		for(int j=1;j<i-2;j++){
			ans=inf,cnt=0;
			dfs(j,i,0);
			if(cnt==2){
				kans++;
			}
		}
//		cout<<kans<<" ";
	}
	cout<<kans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int T=1;cin>>cent>>T;
	while(T--)
	solve();
	
	return 0;
} 
