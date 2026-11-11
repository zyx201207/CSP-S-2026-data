#include<iostream>
using namespace std;
const int M=5e5+5,N=1e5+5;
int c,n,m,d,q,ans;
int w[M],k[M],x[N],y[N];
int a[501][N],t[501][M];
bool v[M][501];
void dfs(int s,int e,int minute,int way){
	if(minute>ans) return;
	if(s==e && minute+t[way][e]<ans){
		ans=minute+t[way][e];
		return;
	}
	
	for(int i=1;i<=k[way];i++){
		if(a[way][i]!=s) dfs(a[way][i],e,minute,way);
	}
	
	for(int i=1;i<=n;i++){
		if(v[i][s] && i!=way) dfs(s,e,minute+t[way][s]+t[i][s],i);
	}
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			v[i][a[i][j]]=1;
		}
		for(int j=1;j<=k[i];j++) cin>>t[i][j];
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++){
		ans=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			if(v[j][x[i]]) dfs(x[i],y[i],0,j);
			cout<<ans<<endl;
		}
	}
	return 0;
}
