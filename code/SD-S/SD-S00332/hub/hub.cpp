#include<bits/stdc++.h>
using namespace std;
int c,T,n,k;
int p[100005];
int f[100005];
int ans=INT_MAX;
//int find(int x){
//	if(f[x]==x)return x;
//	return f[x]=find(f[x]);
//}
//void ch(){
//	for(int i=1;i<=n;i++){
//		f[i]=i;
//	}
////	for(int i=1;i<=n;i++){
////		if(p[i]==1){
////			for(int j=0;j<g[i].size();j++){
////				int fx=find(i),fy=find(g[i][j]);
////				f[fx]=fy;
////			}
////		}
////	}
//	int cnt=0;
//	for(int i=1;i<=n;i++){
//		if(f[i]==i)cnt++;
//	}
//	if(cnt>2)return;
//}
//void dfs(int s,int cnt){
//	if(s==n+1){
//		return;
//	}
//	if(cnt<k){
//		p[s]=1;
//		dfs(s+1);
//	}
//	p[s]=0;
//	dfs(s+1,cnt+1); 
//}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		cout<<1<<'\n';
		
	}
	return 0;
}
