#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int N=5e5+7;
int n,a[N],vis[N],box[N],ans[N],m;
vector<int>e[N];
void dfs(int x){
	for(int i=0;i<e[x].size();i++){
		dfs(e[x][i]);
		vis[x]+=vis[e[x][i]];
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(box[a[i]]!=0){
			vis[i]=1;
			e[box[a[i]]+1].push_back(i);
		}
		else{
			vis[i]=1;
			e[i+1].push_back(i);
			box[a[i]]=i;
		}

	}
	dfs(n+1);
	for(int i=1;i<=n;i++){
		ans[a[i]]+=vis[i];
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
