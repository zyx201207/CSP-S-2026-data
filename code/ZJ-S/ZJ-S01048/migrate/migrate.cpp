#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);i++)
#define foR(i,j,k) for(int i=(j);i>=(k);i--)
#define ull unsigned long long
#define double long double
#define i128 __int128
#define int long long
#define vi vector<int>
#define pb push_back
#define endl "\n"
using namespace std;
const int INF=1e16;
const int N=2e6+10;
int n,d,x[N],ans;
int dis[N],sum[N];
bool vis[N];
void bfs(int st){
	For(i,st+1,n){
		dis[i]=INF;
		sum[i]=0;
		vis[i]=0;
	}
	dis[st]=0;sum[st]=1;vis[st]=1;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();q.pop();
		For(i,u+1,n){
			if(x[i]-x[u]>d)break;
			if(dis[i]>dis[u]+1){
				dis[i]=dis[u]+1;
				sum[i]=sum[u];
				if(vis[i])continue;
				vis[i]=1;
				q.push(i);
			}
			else if(dis[i]==dis[u]+1)
				sum[i]++;
		}
	}
	return;
}
void solve(){
	cin>>n>>d;
	ans=0;
	For(i,1,n)cin>>x[i];
	if(n<4){
		cout<<"0"<<endl;
		return;
	}
	For(i,1,n){
		bfs(i);
		For(j,i+1,n){
			if(sum[j]==2)
				ans++;
		}
	}
	cout<<ans<<endl;
	return;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1,csdbh;
	cin>>csdbh>>T;
	while(T--)solve();
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
