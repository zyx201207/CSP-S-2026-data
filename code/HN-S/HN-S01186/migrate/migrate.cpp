#include<bits/stdc++.h>
#define int long long

using namespace std;

int c,t,n,d,a[2000010];
vector<int>v[2000010];
int work(){
	if(a[2]-a[1]>d) return 0;
	for(int i=1;i<=n;i++){
		if(a[i]-a[1]>d) return n-i;
	}
	return 0;
}
struct str{
	int id,cs;
};
bool bfs(int u,int v){
	queue<str>q;
	bool vis[2000010]={0};
	vis[u]=1;
	int sum=0,zdl=0;
	q.push({u,0});
	while(!q.empty()){
		int g=q.front().id,x=q.front().cs;
		q.pop();
		if(g==v){
			if(!zdl) zdl=x,sum++;
			else if(x==zdl) sum++;
		}
		if(x=zdl+1&&!zdl) return sum=2;
		for(auto z:v[g]){
			if(!vis[z]){
				vis[z]=1;
				q.push({z,x+1});
			}
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans+=bfs(i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
