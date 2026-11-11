#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
long long k[N],xx,yy,ans,a[500][N],c,n,m,d,q,w[N],t[500][N];
void dfs(long long x,long long cnt,long long lin){
	if(x==0){
		return ;
	}
	if(x==yy){
		
		ans=min(cnt+w[yy]+w[xx]+t[lin][x],ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x){
				if(lin==i){
					dfs(a[i][j+1],cnt,i);
				}
				else{
					dfs(a[i][j+1],cnt+t[lin][a[i][j]]+t[i][a[i][j]],i);					
				}

			}
		}
	}
	return;
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
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>xx>>yy;
		ans=500005;
		if(xx>yy){
			swap(xx,yy);
		}
		dfs(xx,0,0);
		cout<<ans<<endl;
	}
	
	return 0;
	//what can i say manbaout
}