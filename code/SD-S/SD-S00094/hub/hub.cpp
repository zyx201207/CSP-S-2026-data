#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,k;
long long choose[100010];
long long dis[1010][1010];
long long fa[100010];
vector<int> p[100010];
int flag[100010];
int record[100010];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int a,int b){
	if(find(a)!=find(b)){
		fa[find(a)]=find(b);
	}
	return;
}
bool check(){
	int cnt=1;
	for(int i=1;i<=k;i++){
		record[i]=find(choose[i]);
	}
	sort(record+1,record+k+1);
	for(int i=2;i<=k;i++){
		if(record[i]!=record[i-1]) cnt++;
	}
	if(cnt>2) return false;
	return true;
}
long long ans[100010];
int op(){
	for(int i=1;i<=n;i++){
		ans[i]=INT_MAX-10;
		for(int j=1;j<=k;j++){
			ans[i]=min(ans[i],dis[i][k]);
		}
	}
	cout<<endl;
	long long iMax=-1;
	for(int i=1;i<=n;i++){
		iMax=max(iMax,ans[i]);
	}
	return iMax;
}
int anszhong=INT_MAX-10;
void dfs(int be,int sum){
	if(sum==k){
		if(check()) anszhong=min(anszhong,op());
		return;
	}
	for(int i=be;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			choose[sum+1]=i;
			dfs(i,sum+1);
			flag[i]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		anszhong=INT_MAX-10;
		for(int i=1;i<=1009;i++){
			for(int j=1;j<=1009;j++){
				dis[i][j]=INT_MAX-10;
			}
		}
		for(int i=1;i<=1009;i++){
			for(int j=1;j<=1009;j++){
				if(i==j) dis[i][j]=0;
			}
		}
		memset(flag,0,sizeof(flag));
		cin>>n>>k;
		int m=n-1;
		for(int i=1;i<=n;i++) fa[i]=i;
		while(m--){
			int u,v;
			cin>>u>>v;
			p[u].push_back(v);
			p[v].push_back(u);
			merge(u,v);
			dis[u][v]=1;
			dis[v][u]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int p=1;p<=n;p++){
					dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
				}
			}
		}
		dfs(1,0);
		cout<<anszhong<<endl;
	}
	return 0;
}
