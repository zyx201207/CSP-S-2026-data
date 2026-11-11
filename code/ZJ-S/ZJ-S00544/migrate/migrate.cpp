#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e6+5;
int a[maxn];
int n,d,ans,res;
void dfs(int u,int e,int cnt){
	if(u==e){
		if(cnt==res) ans++;
		if(cnt<res) ans=1,res=cnt; 
	}
	for(int i=u+1;i<=e;i++){
		if(a[i]-a[u]<=d){
			dfs(i,e,cnt+1);
		}
	}
}
bool check(int a,int b){
	ans=0;
	res=0x3f3f3f3f;
	dfs(a,b,0);
	if(ans==2) return 1;
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int an=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)) an++;
			}
		}
		cout<<an<<"\n";
	}
	return 0;
}