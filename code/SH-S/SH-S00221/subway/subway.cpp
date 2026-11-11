#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[22005],f[1505][1505],x,y,ds,k,a,t,b,T;
vector<int> tu[22005]; 
bool flag=1,flag2=1,vis[22005];
int bfs(int from,int to){
	queue<int> q;
	int cnt=0;
	memset(vis,0,sizeof(vis));
	q.push(from);
	vis[from]=1;
	while(!q.empty()){
		int w=q.front();
		q.pop();
		for(int i=0;i<tu[w].size();i++){
			if(!vis[tu[w][i]]){
				q.push(tu[w][i]);
				vis[tu[w][i]]=1;
				if(tu[w][i]==to) return cnt;
			}
		}
		cnt++;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			f[i][j]=1e9;
		} 
		f[i][i]=0;
	}
	ds=m+n;
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k>2) flag2=0;
		if(k==2){
			ds--;
			cin>>a>>t>>b>>c;
			f[a][b]=min(f[a][b],t+c);
			f[b][a]=min(f[b][a],t+c); 
		}
		else{
			for(int j=1;j<=k;j++){
			    cin>>a>>t;
			    if(i==1&&j==1) T=t;
			    if(T!=t) flag=0; 
			    if(ds<=2000){
			    	f[a][m+i]=min(f[a][m+i],t);
			        f[m+i][a]=min(f[m+i][a],t);
				}
			    tu[a].push_back(m+i);
			    tu[m+i].push_back(a);
		    }
		}
	}
	if(flag==0||flag2==1)
	    for(int i=ds;i>=1;i--)
		    for(int j=ds;j>=1;j--)
			    for(int mi=1;mi<=ds;mi++)
				    f[i][j]=min(f[i][j],f[i][mi]+f[mi][j]);
	while(q--){
		cin>>x>>y;
		if(flag==1&&flag2==0){
			cout<<bfs(x,y)*T+w[x]+w[y]<<endl;
		}
		else cout<<f[x][y]+w[x]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}// floyd 32pts+bfs 12pts
