#include<bits/stdc++.h>
#define ll long long
#define N 4005
using namespace std;

namespace WDY_Hodur{

int c,T;
int n,k;
vector<int>g[N];

int dep[N],fa[N],mx;
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	if(dep[x]>dep[mx])mx=x;
	for(int y:g[x]){
		if(y==fa[x])continue;
		fa[y]=x,dfs(y);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1);
		for(int i=1;i<=n;i++)dep[i]=0;
		dfs(mx);
		
		int ans=(dep[mx]+1)/2;
		cout<<ans/2;
	}
	return 0;
}

}

int main(){
	WDY_Hodur::main();
	return 0;
}
