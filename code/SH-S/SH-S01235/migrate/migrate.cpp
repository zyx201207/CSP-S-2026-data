#include<bits/stdc++.h>
using namespace std;
bool vis[2000020];

int cnt;
int n,d;
int x[2000020]={};
void dfs(int zb,int ed){
	if(abs(x[ed]-x[zb])<=d){
		cnt++;
		
		return;
	}
	for(int i=zb+1;i<ed;i++){
		
		int dis=x[i]-x[zb];
		dis=abs(dis);
		if(dis<=d){
			dfs(i,ed);
		}
	}
	
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	
	while(t--){
		memset(x,0,sizeof(x));
		
		cin>>n,d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				
				
				cnt=0;
				memset(vis,0,sizeof(vis));
				dfs(i,j);
					
				if(cnt==0)ans++;
					
				
			}
			
		}
		cout<<ans<<endl;
		
		
	}
	
	 
	return 0;
	
}
