#include<bits/stdc++.h>
#define int long long
#define fi first
#define N 1001000
#define M 100100
#define P 998244353
#define PX 1000000007
#define se second
#define all(x) x.begin(),x.end()
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mod(x) (((x%P)+P)%P)
using namespace std;
int n,m,a[N],ans,nex[N],k[N],s[N],s2[N];
vector<int> g[N];
void dfs(int x){
	for(int i:g[x]){
		dfs(i);
		s[x]+=s[i];
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	fst;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		nex[i]=k[a[i]];
		k[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(nex[i]==0){
			if(i!=n)g[a[i+1]].push_back(a[i]);
		}
		s[a[i]]++;
	}
	dfs(a[n]);
	for(int i=1;i<=m;i++){
		if(i!=m)cout<<s[i]<<' ';
		else cout<<s[i];
	}
	return 0;
}

