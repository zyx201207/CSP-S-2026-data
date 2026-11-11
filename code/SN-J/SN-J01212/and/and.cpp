#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
int n,m;
ll a[N];
ll maxn;
ll ans;

bool vis[N];
vector <ll> vec;
void dfs(int idx,int m){
	if(idx==m){
		ans=vec[1];
		for(int i : vec) ans&=i;
		maxn=max(maxn,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		vec.push_back(a[i]);
		dfs(idx+1,m);
		vis[i]=false;
		vec.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn<<endl;
		return 0;
	}else if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn<<endl;
		return 0;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans<<endl;
		return 0;
	}else if(m==n-1){
		maxn=0;
		for(int i=1;i<=n;i++){
			if(i!=1) ans=a[2];
			else ans=a[1];
			for(int j=1;j<=n;j++) if(i!=j) ans&=a[j];
			maxn=max(maxn,ans);
		}
		cout<<maxn<<endl;
		return 0;
	}else{
		maxn=0;
		dfs(0,m);
		cout<<maxn<<endl;
	}
	return 0;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
