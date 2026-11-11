#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
	//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
//0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6

	int dis[55][50];
    int cnt[50][50];
    int a[50];
    memset(dis,0,sizeof dis);
    memset(cnt,1,sizeof cnt);
    memset(a,0,sizeof a);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
//	if(n>5000) cout<<0<<endl;
//	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int vis[505]={0};
		queue<int> q;
		q.push(i);
		vis[i]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int j=1;j<=n;j++){
				if(vis[j]==0 && abs(a[j]-a[u])<=d){
					vis[j]=1;
					dis[i][j]=dis[i][u]+1;
					q.push(j);
				}
			}
		}
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		for(int k=i+1;k<=j-1;k++){
			if(dis[i][j]==dis[i][k]+dis[k][j]) cnt[i][j]++;
		}
	}
	}
	int q=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cnt[i][j]==2) q++;
		}
	}
	cout<<q<<endl;
}
	return 0;
}
