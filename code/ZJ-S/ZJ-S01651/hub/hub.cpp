#include<bits/stdc++.h>
using namespace std;
vector<int>a[2000001];
int zt[101];
int c[101];
int step[101][101];
void dfs1(int x){
	for(auto y:a[x]){
		if(zt[y]==1&&c[y]==0){
			c[y]=1;
			dfs1(y);
		}
	}
}
void dfs2(int x,int ks){
	for(auto y:a[x]){
		if(step[ks][y]==0){
			step[ks][y]=step[ks][x]+1;
			dfs2(y,ks);
		}
	}
}
int main(){
//	freopen("hub2.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	int ca,t;
	cin>>ca>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			a[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			a[x].push_back(y),a[y].push_back(x);
		}
		if(n<=10){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)
					step[i][j]=0;
			}
			for(int i=1;i<=n;i++)
				step[i][i]=1,dfs2(i,i);
			int ans=1e9;
			for(int i=0;i<(1<<n);i++){
				int cnt=0,jsq=0;
				for(int j=0;j<n;j++){
					if((i>>j)&1)
						zt[j+1]=1,cnt++;
					else
						zt[j+1]=0;
				}
				if(cnt!=k)
					continue;
				for(int j=1;j<=n;j++)
					c[j]=0;
				for(int j=1;j<=n;j++){
					if(c[j]==0&&zt[j]==1){
						jsq++;
						dfs1(j);
					}
				}
				if(jsq<=2){
					int maxx=0;
					for(int j=1;j<=n;j++){
						int minn=1e9;
						for(int l=1;l<=n;l++){
							if(zt[l]==1)
								minn=min(minn,step[j][l]-1);
						}
						maxx=max(maxx,minn);
					}
					ans=min(ans,maxx);
				}
			}			
			cout<<ans<<endl;
		}
	}
	return 0;
}