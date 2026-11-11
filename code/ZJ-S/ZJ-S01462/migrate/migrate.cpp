#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=2e6+10;

int n,d;
int A[N],cnt[N];
vector<int> lsh;

int find(int x){
	return lower_bound(lsh.begin(),lsh.end(),x)-lsh.begin();
}

void solve(){
	cin>>n>>d; lsh.clear();
	for(int i=1;i<=n;i++) cnt[i]=0;
	for(int i=1;i<=n;i++) cin>>A[i],lsh.push_back(A[i]);
	sort(lsh.begin(),lsh.end());
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(A[j]-A[i])<=d) cnt[find(A[j])]++;
		}
		int mx=-1;
		for(int j=i-1;j>=1;j--){
			mx=max(mx,cnt[find(A[j])]);
		}
		if(mx==2) ans++;
	}
//	for(int i=1;i<=n;i++) cout<<cnt[find(A[i])]<<" ";
	cout<<ans<<'\n';
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("mirgage.in","r",stdin);
	freopen("mirgate.out","w",stdout);
	int c,t; cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
