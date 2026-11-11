#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int t,l;
};
struct edge{
	int id,ds;
};
ll c,n,m,d,q;
ll mis[500005];
ll w[500005],f[5005][5005];
vector<node> v[505005];
/*int bfs(int x,int y){
	memset
	queue<node> q;
	q.push({x,0});
	while(!q.empty()){
		int nd=q.front().id,ns=q.front().ds;
		q.pop();
		if(f[nd]&&ns>=mis[nd]) continue;
		mis[nd]=ns,f[nd]=1;
		for(int i=0;i<v[nd].size();i++){
			int cd=v[nd][i].t,cs=ns+v[nd][i].l;
			q.push({cd,cs});
		}
	}
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=5002;i++) f[i][i]=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k,a,t,x,y;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			f[i+m][a]=f[a][i+m]=t;
		}
	}
	for(int p=1;p<=m+n;p++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
}
