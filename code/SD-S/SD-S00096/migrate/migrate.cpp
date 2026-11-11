#include<bits/stdc++.h>
#define int long long
#define fr first
#define sc second
#define ls(p) (p<<1)
#define rs(p) ((p<<1)|1)

using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int const INF=1e9,N=2e6+5;
int n,m,cnt,ans,c,a[N],d;
int g[505][505],f[505][505];
vector<int> tmp;
bool vis[N];
void sol(){
	n=read(),d=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=INF;
			g[i][j]=0;
		}
	}
	ans=0;
	for(int l=2;l<=n;l++){
		for(int i=1;i<=n;i++){
			int j=i+l-1;
			if(j>n) break;
			int y=0;
			if(a[j]-a[i]<=d){
				f[i][j]=1;
				g[i][j]=1;
				continue;
			}
			for(int k=i;k<=j;k++) vis[k]=0;
			int k=i,cnt=0;
			bool ff=0;
			while(k!=j){
				int lst=k;
				vis[k]=1;
				cnt++;
				if(a[k+1]-a[k]>d){
				    ff=1;
					break;
				}
				while(a[k+1]-a[lst]<=d&&k!=j){
					k++;
				}
			}
			if(ff) continue;
			y=1;
			for(int k=i+1;k<j;k++){
				if(vis[k]) continue;
				if(f[i][k]+f[k][j]==cnt){
					y+=g[i][k]*g[k][j];
					if(y>3) y=3;
				}
			}
			f[i][j]=cnt;
			g[i][j]=y;
			if(y==2){
//				cerr<<i<<" "<<j<<'\n';
//				cerr<<cnt<<'\n';
				ans++;
			} 
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	int T=read();
	while(T--){
		sol();
	}
	return 0;
}

