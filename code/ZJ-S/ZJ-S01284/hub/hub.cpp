#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;
int n,k;
int dep[N],fa[N],dis[N];
vector<int>g[N];
void dfs(int u,int fath){
	dep[u]=dep[fath]+1,fa[u]=fath;
	for(int v:g[u])if(v!=fath)dfs(v,u);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,0);
		int max_1=-1,max_2=-1,flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			if(dep[i]>max_1)max_2=max_1,flag2=flag1,max_1=dep[i],flag1=i;
			else if(dep[i]>max_2)max_2=dep[i],flag2=i;
		}
		int length=max_1+max_2;
//		cout<<flag1<<" "<<flag2<<"\n";
		if(length>n)length=0;
		cout<<max(1,length/4-(k-2)/3)<<"\n";
	}
	return 0;
}
