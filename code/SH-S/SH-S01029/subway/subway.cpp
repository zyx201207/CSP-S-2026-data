#include<bits/stdc++.h>
using namespace std;
long long c,n,m,minn=0,d,q,cnt=0,w[500010],k[510],a[510][500010],t[510][500010],rx,ry,vis[500010],viss[510];
void dfs(long long x,long long ss,long long bb){
	if(x==ry){
		cnt+=t[ss][bb];
		minn=min(minn,cnt);
		return ;
	}
	vis[x]=1;
	for(int i=1;i<=n&&viss[i]==0;i++){
		for(int j=1;j<=k[i];j++){
			
			
			if(a[i][j]==x){
				cnt=cnt+(t[i][j]+t[ss][bb]);
				
				for(int f=1;f<=k[i];f++){
					if(vis[a[i][f]]==0){
				     	
				        viss[ss]=1;
			        	
						dfs(a[i][f],i,f);
						vis[x]=0;
				        viss[ss]=0;
			        	cnt=cnt-(t[i][j]+t[ss][bb]);
					}
				}
				
				
			}
			
			
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	while(q--){
		minn=0;
		cin>>rx>>ry;
		cnt=w[rx]+w[ry];
		dfs(rx,0,0);
		cout<<minn<<endl;
	}
	return 0;
}
