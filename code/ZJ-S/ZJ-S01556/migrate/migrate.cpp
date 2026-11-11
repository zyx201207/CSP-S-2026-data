#include <bits/stdc++.h>
using namespace std;
long long d,n;
long long x[2000050];
int dis[2000050];
int ans[2000050];
void dfs(int xx,int sum){
	if(dis[xx]<sum){
		return ;
	}
	if(dis[xx]==sum){
		ans[xx]++;
	} 
	if(dis[xx]>sum){
		dis[xx]=sum;
		ans[xx]=1;
	}
	for(int i=xx+1;i<=n;++i){
		if(abs(x[xx]-x[i])<=d){
			dfs(i,sum+1);
		} 
	}
} 
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		long long anss=0;
		for(int i=1;i<=n;++i){
			for(int i=1;i<=n;++i){
				dis[i]=1e8;
				ans[i]=0;
			}
			dfs(i,0);
			for(int i=1;i<=n;++i){
				if(ans[i]==2){
					++anss;
				}
			}
		}
		cout<<anss<<endl;
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
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/
