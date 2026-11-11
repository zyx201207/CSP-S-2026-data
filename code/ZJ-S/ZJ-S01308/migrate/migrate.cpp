#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int text,T,n,d,pos,ans;
int a[N],dp[N][N],flag[N];
struct node{
	int x,dis;
};
void bfs(int qd){
	queue<node> q;
	q.push(node{qd,0});
	while(q.size()>0){
		int x=q.front().x;
		int dis=q.front().dis;
		q.pop();
		for(int i=x+1;i<=n;i++){
			if(a[i]-a[x]>d) break;
			if(dis+1>dp[qd][i]) continue;
			if(dis+1==dp[qd][i]) flag[i]++;
			q.push({i,dis+1});
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>text>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		memset(flag,0,sizeof flag);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			pos=i;dp[i][i]=0;
			for(int j=i+1;j<=n;j++){
				if(a[j]>a[pos]+d){
					if(pos==j-1) break;
					pos=j-1;
				}
				dp[i][j]=dp[i][pos]+1;
			}
		}
		for(int i=1;i<=n;i++){
			memset(flag,0,sizeof flag);
			bfs(i);
			for(int j=i+1;j<=n;j++)
				if(flag[j]==2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}