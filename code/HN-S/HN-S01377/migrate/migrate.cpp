#include<bits/stdc++.h>
using namespace std;
const int N=2000006;
int n;
long long d,x[N],cnt=0;
bool vis[N];
void dfs(int u,int v,int pos){
	if(u==v){
		cnt++;
		return ;
	}
	for(int i=u+1;i<=v;i++){
		if(vis[i]==true)continue;
		if(x[i]-x[u]<=d){
			dfs(i,v,pos);
			if(pos!=u)return ;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c;
	if(c==0){
		int t;
		cin>>t;
		while(t--){	
			cin>>n>>d;
			long long s=1000000000000000001;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				s=min(x[i]-x[i-1],s);
			}
			if(s>d){
				cout<<0;
				continue; 
			}
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					
					dfs(i,j,i);
					if(cnt==2)ans++;
				}
			}
			cout<<ans+1<<endl;
		}
	}
	return 0; 
}
/*
0 1
4 2
1 2 3 4

0 2
5 3
-2 -10 12
6 2
-4 -3 -2 -1 3 6
*/
