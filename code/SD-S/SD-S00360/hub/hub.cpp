#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,t;
int u[N],v[N],n,k;
vector<int> e[N];
int countm(int x){
	int res=0;
	while(x){
		++res;
		x&=(x-1);
	}
	return res;
}
int f[15][15];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
			e[u[i]].emplace_back(v[i]);
			e[v[i]].emplace_back(u[i]);
			f[u[i]][v[i]]=1;
			f[v[i]][u[i]]=1;
		}
		int minn=1e18;
		for(int mask=0;mask<(1<<n);mask++){
			if(countm(mask)!=k) continue;
			int sum=-1e18;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=1e18;
					f[j][i]=1e18;
				}
			}
			for(int i=1;i<n;i++){
				f[u[i]][v[i]]=1;
				f[v[i]][u[i]]=1;
			}
			vector<int> q;
			
			for(int i=1;i<=n;i++){
				if(mask&(1<<(i-1))){
					q.emplace_back(i);
				}
			}
			for(auto i:q){
				for(int j:q){
					f[i][j]=0;
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(f[i][j]!=1e18) sum=max(sum,f[i][j]);
				}
			}
			minn=min(minn,sum);
		}
		cout<<minn<<"\n";
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
ºÃÄÑ°¡ 
*/

