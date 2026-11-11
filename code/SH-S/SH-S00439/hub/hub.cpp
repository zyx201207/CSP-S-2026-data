#include<bits/stdc++.h>
using namespace std;
struct node{
	bool way[1005];
}city[1000];
int dfs(int rt,int len,int pl){
	if(city[rt].way[pl]==true){
		return len;
	}else{
		len++;
		int a=dfs(rt,len,pl);
		return a;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			city[a].way[b]=true;
			city[b].way[a]=true;
		}
		int ans=100000;
		int g[1005]; 
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int olo=dfs(i,0,j);
				g[i]=min(g[i],olo);
			}
		}
		sort(g,g+n-1);
		cout<<g[n-k+1]<<endl;
	}
	return 0;//PLEASE AC;
}
