#include<bits/stdc++.h>
using namespace std;
int dis[1010][1010],a[20],mins=INT_MAX;
int n,k;
bool check(){
	int cnt=0;
	for(int i=1;i<=k;i++){
		int mins=INT_MAX;
		for(int j=1;j<=k;j++){
			if(i!=j) mins=min({mins,dis[a[i]][a[j]],dis[a[j]][a[i]]});
		}
		if(mins>1) cnt++;
	}
	return cnt<=2;
}
void dfs(int x,int cnt){
	if(cnt==k){
		int maxs=0;
		for(int i=1;i<=n;i++){
			int minx=INT_MAX;
			for(int j=0;j<k;j++){
				minx=min({minx,dis[i][a[j]],dis[a[j]][i]});
			}
			maxs=max(maxs,minx);
		}
		if(check()) mins=min(mins,maxs);
	}
	for(int i=x+1;i<=n;i++){
		a[cnt]=i;
		dfs(i,cnt+1);
		a[cnt]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=3 || c==7){
		while(t--){
			cin>>n>>k;
			memset(dis,0x3f,sizeof dis);
			for(int i=1;i<n;i++){
				int x,y;
				cin>>x>>y;
				dis[x][y]=dis[y][x]=1;
			}
			for(int i=1;i<=n;i++) dis[i][i]=0;
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}
			}
			mins=INT_MAX;
			dfs(0,0);
			cout<<mins<<"\n";
		}
	}
	return 0;
}

