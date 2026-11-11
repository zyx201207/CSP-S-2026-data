#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=306;
int n,d,l;
int a[N];
int f[N][N],m[N][N],v[N];
void bfs(int x){
	queue<int>q;
	q.push(x);
	f[x][x]=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=t+1;i<=n&&a[i]-a[t]<=d;i++){
			f[x][i]=min(f[x][t]+1,f[x][i]);
			q.push(i);
		}
	}
	
}
void dfs(int x){
	for(int i=x+1;i<=n&&a[i]-a[x]<=d;i++){
		if(i<=x&&v[x]||f[l][x]>f[l][i]||m[l][i]>2)continue;
		if(f[l][i]==f[l][x]+1&&!v[x])m[l][i]++,v[x]=1;
		dfs(i);

	}	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int fl=1;fl<=t;fl++){
		memset(m,0,sizeof(m));
		memset(f,0x3f,sizeof(f));
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)memset(v,0,sizeof(v)),bfs(i),l=i,dfs(i);
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(m[i][j]==2)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}

