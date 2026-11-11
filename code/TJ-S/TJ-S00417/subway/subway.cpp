#include <bits/stdc++.h>
using namespace std;
int w[505],t[505];
bool vis[505];
int dx[2]={1,2};
int c,m,n,d,q;
int x,y,k,ans;
int check(int x){
	if(check(x)==x) return x;
	return check(w[x]);
}
void find(int x,int y){
    if(x==y) return;
    for(int i=0;i<2;i++){
       if(vis[i+x]==0&&x>0&&x<n){
       	vis[i+x]=1;
       	ans+=w[i];
        find(i+x,y);
        vis[i+x]=0;
	   }
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	cin>>k;
	int pp=2*k+1;
	for(int i=1;i<=pp;i++){
		int a;
		cin>>a>>t[i];
	}
	while(q--){
		cin>>x>>y;
		dfs(x,y);
		cout<<ans<<"\n";
	}
	return 0;
} 
