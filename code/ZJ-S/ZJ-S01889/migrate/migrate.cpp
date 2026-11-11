#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxN=5e3+5;

int n;
ull d;
ll a[maxN];
int path;
bool flag;
ll ans;
int mins;
void dfs(int root,int r,int time){
	if (root==r){
		mins=min(mins,time);
		if (mins==time) path++;
		if (path>2) exit(0);
		return;
	}
	for (int i=r;i>=root+1 && !flag;i--){
		if (a[i]-a[root]<=d) dfs(i,r,time+1);
	}
}
void deal(int l,int r){
	path=0;
	mins=r-l+1;
	flag=false;
	dfs(l,r,0);
	if (path==2) ans++;
}
void solve(){
	cin>>n>>d;
	for (int i=1;i<=n;i++) cin>>a[i];
	ans=0;
	for (int i=1;i<=n;i++){
		for (int j=i+3;j<=n;j++){
			deal(i,j);
		}
	}
	cout<<ans<<endl;
}

int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while (t--){
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}