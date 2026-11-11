#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,ans=INT32_MIN;
vector<int> a,c;
void dfs(int,int);
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;cin>>x;a.push_back(x);
	}
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
void dfs(int cur,int sel){
	if(sel>=m){
		int res=c[0];
		for(int i=1;i<m;i++){
			res&=c[i];
		}
		ans=max(res,ans);
		return;
	}
	if(sel+(n-cur+1)<m)return;
	if(cur>=n)return;
	c.push_back(a[cur]);
	dfs(cur+1,sel+1);
	c.erase(c.end()-1);
	dfs(cur+1,sel);
}
