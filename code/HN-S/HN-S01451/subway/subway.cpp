#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],k[501],x,y;
long long ans=1000000000000000000;
vector<int> a[501],t[501],way[500001];
bool flag[501];
void dfs(int u,int v,long long spend){
//	cout<<u<<' '<<v<<' '<<spend<<endl; 
	int tim;
	if(u==v){
		if(spend<ans){
			ans=spend;
		}
		return;
	}
	if(spend>ans){
		return;
	}
	for(int i=0;i<way[u].size();i++){
		for(int j=1;j<=k[way[u][i]];j++){
			if(a[way[u][i]][j]==u){
				tim=t[way[u][i]][j];
//				cout<<way[u][i]<<' '<<j<<endl;
				break;
			}
		}
	}
	for(int i=0;i<way[u].size();i++){
		for(int j=1;j<=k[way[u][i]];j++){
			if(a[way[u][i]][j]!=u&&flag[a[way[u][i]][j]]==0){
				flag[a[way[u][i]][j]]=1;
				dfs(a[way[u][i]][j],v,spend+tim+t[way[u][i]][j]);
				flag[a[way[u][i]][j]]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//Oct31==Dec25?
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(-1);
		t[i].push_back(-1);
		for(int j=1;j<=k[i];j++){
			cin>>x;
			a[i].push_back(x);
			cin>>y;
			t[i].push_back(y);
			way[x].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			flag[j]=0;
		}
		ans=1000000000000000000;
		dfs(x,y,w[x]+w[y]);
		cout<<ans<<endl;//0 3 7 20 2 8 3 6 1 7 2 9 3 1 4 2 5 5 100 3 2 6 3 1 7 2 4 3 2 5 100 4 6 6 7 1 6 2 3
	}//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
	return 0;
}
