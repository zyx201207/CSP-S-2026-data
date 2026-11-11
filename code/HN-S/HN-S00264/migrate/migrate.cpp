#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000006];
int cnt[10004][10004],dist[10004][10004];
void dfs(int now,int root){
	for(int i=1;i+now<=n;i++){
		if(a[i+now]-a[now]>d)break;
		if(dist[now][root]+1<dist[now+i][root]){
			cnt[now+i][root]=1;
			dist[now+i][root]=dist[now][root]+1;
		}
		else if(dist[now][root]+1==dist[now+i][root]){
			cnt[now+i][root]++;
		}
//		else continue;
//		cout<<cnt[now][root]<<'\n';
		dfs(now+i,root);
		
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dist[i][j]=0x7fffffff;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dist[i][i]=0;
			dfs(i,i);
			for(int j=i;j<=n;j++){
				if(cnt[j][i]==2)ans++;
				cnt[j][i]=0;
			}
		}
		cout<<ans<<'\n';
	}
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/ 
