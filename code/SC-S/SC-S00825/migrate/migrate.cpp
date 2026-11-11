#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pa; 
const int MAXN=2e6+6,MAXK=3e3+3,INF=1e9;
int c,T,n;
long long d,x[MAXN]; 
int f[MAXK][MAXK],r[MAXK][MAXK];
int dis[MAXN],r2[MAXN];
priority_queue<pa,vector<pa>,greater<pa> > q;
bool vis[MAXN];
void solve(){
	int pos=lower_bound(x+1,x+n+1,x[1]+d)-x-1;
	if(x[pos+1]<=x[1]+d&&pos<n) pos++;
	for(int i=2;i<=n;i++) dis[i]=INF,r2[i]=vis[i]=0;
	vis[1]=0;
	q.push({0,1});
	r2[1]=1;
	int p;
	while(!q.empty()){
		p=q.top().second;
		q.pop();
		if(vis[p]) continue ;
		vis[p]=1;
		for(int i=p+1;i<=min(p+pos-1,n);i++){
			if(vis[i]) continue ;
			if(dis[i]==dis[p]+1) r2[i]+=r2[p];
			else if(dis[i]>dis[p]+1){
				dis[i]=dis[p]+1;
				q.push({dis[i],i});
				r2[i]=r2[p];
			}
		}
	}
	long long ans=0;
	for(int i=2;i<=n;i++){
		if(r2[i]==2) ans+=n-i+1;
//		printf("(%d,%d)",r2[i],dis[i]);
	}
	cout<<ans<<"\n";
	return ;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int pos;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11||c==12){
			solve();
			continue ;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++) f[i][j]=INF,r[i][j]=0;
		for(int i=1;i<=n;i++){
			pos=lower_bound(x+1,x+n+1,x[i]+d)-x-1;
			if(x[pos+1]<=x[i]+d&&pos<n) pos++;
			for(int j=i+1;j<=pos;j++) f[i][j]=1,r[i][j]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<k;i++)
				for(int j=k+1;j<=n;j++){
					if(f[i][k]+f[k][j]==f[i][j]) r[i][j]+=r[i][k]*r[k][j];
					if(f[i][k]+f[k][j]<f[i][j]){
						r[i][j]=r[i][k]*f[k][j];
						f[i][j]=f[i][k]+f[k][j];
					}
				}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(r[i][j]==2) ans++; 
		cout<<ans<<"\n";
	}
	return 0;
}
/*
暴力 32 pts 是好写的（1-6的小样例和11-12的特殊数据点）
可以做到 O(n^3)
考虑 floyd 暴力建图来统计路径条数 
*/ 