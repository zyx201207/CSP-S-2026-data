#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+5;

int a[N],box[N];
int n,m;
bool vis[N];
int ans=-1e9;

void dfs(int cur){
	if(cur>m){
		int cnt=box[1]&box[2];
		for(int i=3;i<=m;i++){
			cnt=cnt&box[i];
		}
		ans=max(ans,cnt);
//		for(int i=1;i<=m;i++){
//			cout<<box[i]<<" ";
//		}
//		cout<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			box[cur]=a[i];
			vis[i]=1;
			dfs(cur+1);
			vis[i]=0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int maxx=-1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		int cnt=a[1]&a[2];
		for(int i=3;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<"\n";
	dfs(1);
	cout<<ans;
	return 0;
}

