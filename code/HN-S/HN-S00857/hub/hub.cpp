#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k;
int d[333][333],di[333][333];

int st[500010],a[500010],ss[500010],ddd[500010];
int mi=1000000000000000000;
void dd(int x){
	ss[x]=1;
	for(int y=1;y<=n;y++){
		if(ddd[y]&&d[x][y]==1&&ss[y]==0){
			dd(y);
		}
	}
}
void dfs(int x){
	if(x==k+1){
		for(int i=1;i<=n;i++)ss[i]=0,ddd[i]=0;
		int id=0;
		for(int i=1;i<=k;i++)ddd[a[i]]=1;
		for(int i=1;i<=k;i++){
			if(ss[a[i]]==0){
				id++;
				dd(a[i]);
			}
		}
		if(id<=2){
			int mx=0;
			for(int i=1;i<=n;i++){
				if(ddd[i]==1)continue;
				int mii=1000000000000000000;
				for(int j=1;j<=n;j++){
					if(ddd[j]==0)continue;
					mii=min(mii,di[i][j]);
				}mx=max(mx,mii);
			}
			mi=min(mi,mx);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			a[x]=i;
			dfs(x+1);
			st[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(n<=300){
			mi=1000000000000000000;
			cin>>n>>k;
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=0;
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)di[i][j]=1000000000000000000;
			for(int i=1;i<=n;i++)di[i][i]=0;
			for(int i=1;i<n;i++){
				int x,y;
				cin>>x>>y;
				d[x][y]=d[y][x]=1;
				di[x][y]=di[y][x]=1;
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						di[i][j]=min(di[i][j],di[i][k]+di[k][j]);
					}
				}
			}
			dfs(1);
			cout<<mi<<"\n";
		}
		else{
			cout<<"0\n";
		} 
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
