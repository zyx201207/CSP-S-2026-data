#include<bits/stdc++.h>
#define qwq return 0;
#define int long long
using namespace std;
int c,t,n,m,d[5005][5005],f[5005][5005],y[5005],v[5005],cnt;
struct node{
	int s,ans;
};
queue<node> q;
void bfs(int s){
	memset(v,0,sizeof(v));
	q.push((node){s,0});
	v[s]=1;
	while(q.size()){
		node now=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(!v[i]){
				if(d[now.s][i]!=-1)	if(now.ans+1<=d[now.s][i]) d[now.s][i]=now.ans+1,d[i][now.s]=now.ans+1,f[now.s][i]++,f[i][now.s]++,v[i]=1,q.push((node){i,now.ans+1});
				else d[now.s][i]=now.ans+1,d[i][now.s]=now.ans+1,f[now.s][i]++,f[i][now.s]++,v[i]=1,q.push((node){i,now.ans+1});
		    }
		}
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(d,-1,sizeof(d));
		memset(f,-1,sizeof(f));
		memset(y,-1,sizeof(y));
		cnt=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>y[i];
		for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) if(y[j]-y[i]<=m) d[i][j]=1,d[j][i]=1,f[i][j]++,f[j][i]++;
		for(int i=1;i<=n;i++) bfs(i);
		for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) if(f[i][j]==2) cnt++;
		cout<<cnt<<'\n';
	}
	qwq
}
//Oct31==Dec25?
