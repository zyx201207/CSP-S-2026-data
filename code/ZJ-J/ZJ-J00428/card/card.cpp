#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e5+10,M=3e5+10;
int n,m;
bool vis[M];
int a[N],ans[M];
void solve(int pos){
	vector<int> v;
	memset(vis,false,sizeof(vis));
	for(int i=pos;i<=n;i++){
		if(vis[a[i]]){
			while(v.back()!=a[i]){
				vis[v.back()]=false;
				v.pop_back();
			}
		}
		else{
			vis[a[i]]=true;
			v.push_back(a[i]);
		}
	}
	for(int& x:v) ans[x]++;
	return;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<flush;
	fclose(stdin),fclose(stdout);
	return 0;
}
