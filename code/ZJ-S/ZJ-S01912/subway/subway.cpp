#include<bits/stdc++.h>
using namespace std;
const int N=505;
int c,n,m,d,q,w[N],k[N],mn=INT_MAX;
int a[N][N],t[N][N],s,e,tme,color[N];
vector<int> g[N],color1[N];
bool vis[N];
bool check(int s,int e){
	for(auto x:color1[s])
		for(auto y:color1[e])
			if(x==y) return true;
	return false;
}
void dfs(int x,int sum){
	//cout<<x<<" "<<sum<<"\n";
	if(x==e){
		mn=min(mn,sum+t[color[e]][e]+w[e]);
		return ;
	} 
	vis[x]=true;
	for(auto y:g[x]){
		if(!vis[y]){
			if(color[x]!=color[y])
				dfs(y,sum+t[color[x]][y]+t[color[y]][y]);
			else dfs(y,sum);
		}
	}vis[x]=false;
}                               
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>tme;
			t[i][a[i][j]]=tme; color[a[i][j]]=i; 
			color1[a[i][j]].push_back(i);
		}
		for(int j=1;j<k[i];j++){
			g[a[i][j]].push_back(a[i][j+1]);
		}               
	}                                  
	while(q--){
		cin>>s>>e;
		if(check(s,e)) cout<<w[s]+t[color[s]][s]+w[e]+t[color[s]][e]<<"\n";
		else{
			dfs(1,w[s]+t[color[s]][s]); 
			cout<<mn<<"\n";
			mn=INT_MAX;
		}
	}
	return 0;
}                        
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/