#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
const unsigned long long MAXX=1e12;
int c,n,m,d,p,xx,k,st,en; 
long long w[N],vis[505][N];
int fx[]={0,0,-1,1};
int fy[]={-1,1,0,0};
unsigned long long ans,a[505][N];
void fun(int y,int x,unsigned long long z){
	if(x==en){
		ans=min(ans,z+a[y][x]);
		return;
	}else{
		for(int i=0;i<4;i++){
			int nx=x+fx[i];
			
			int ny=y;
			
			if(a[ny][nx]==0||vis[ny][nx]==1) continue;
			if(ny<=0||ny>n) continue;
			if(nx<=0||nx>m) continue;
			if(fx!=0){
				vis[ny][nx]=1;
				fun(y,nx,z);
				vis[ny][nx]=0;
			}else{
				for(int i=1;;i++){
					ny+=fy[i];\
					if(ny<=0||ny>n) break;
					if(nx<=0||nx>m) break;					
					if(a[ny][nx]==0||vis[ny][nx]==1) continue;

					fun(ny,nx,z+a[ny][nx]+a[y][nx]);
				}
			}
			
			
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cout<<w[i];
	}for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>xx;
			cin>>a[i][xx];
		}
	}
	while(p--){
		cin>>st>>en;
		ans=MAXX;
		if(st==en){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i][st]!=0){
				vis[i][st]=1;
				fun(i,st,a[i][st]);
				vis[i][st]=0;
			}
		}
		ans+=w[st]+w[en];
		cout<<ans<<'\n';
	}
	
	
	
	return 0;
}