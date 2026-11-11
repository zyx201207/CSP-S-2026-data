#include <bits/stdc++.h>
#define int long long
const int N=2e6+100;
using namespace std;
typedef pair<int,int> pii;
int n,d;
int x[N];
int dis[N],cnt[N];
queue<int> q;
int dfs(int k){
	while(!q.empty())q.pop();
	q.push(k);
	dis[k]=0;
	while(!q.empty()){
		int it=q.front();
		q.pop();
		for(int i=it;i<=n;i++){
			if(x[i]-x[it]>d)break;
			if(dis[i]==dis[it]+1){
				cnt[i]++;
				q.push(i);
			}
			else if(dis[i]>dis[it]+1){
				cnt[i]=1;
				dis[i]=dis[it]+1;
				q.push(i);
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]==2&&i!=k)res++;
	}
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
	
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cnt[i]=0;
		} 
		for(int i=1;i<=n;i++){
			scanf("%lld",x+i);
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int i=1;i<=n;i++){
				dis[i]=1e18;
			}
			ans+=dfs(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 20 2
5 3
-2 -1 0 1 20 2
5 3
-2 -1 0 1 2

*/
