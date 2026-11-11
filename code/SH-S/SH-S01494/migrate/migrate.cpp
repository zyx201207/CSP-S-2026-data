#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6;
int n,d,mi_num=1;
int a[N];
int mi[N];
bool vis[N];
void dfs(int dis,int pos,int en){
	if(pos==en){
		mi[mi_num]=dis;
		mi_num+=1;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]||pos==i){
			continue;
		}
		if(abs(a[pos]-a[i])>d){
			continue;
		}
		vis[i]=1;
		dfs(dis+1,i,en);
	}
}
int solve(int be,int en){
	
	memset(vis,0,N);
	vis[be]=1;
	dfs(1, be,en);
	int m=1e9;
	for(int i=1;i<mi_num;i++){
		m=min(m,mi[i]);
	}	
	int ans=0;
	for(int i=1;i<mi_num;i++){
		if(mi[i]==m){
		ans++;
		}
	}
	if(ans==2){
		return 1;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	while(t--){		
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				cnt+=solve(i,j);
			}
		}
		cout<<cnt/3<<endl;		
	}
	return 0;
}
