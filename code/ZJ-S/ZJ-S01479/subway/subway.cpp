#include<bits/stdc++.h>
using namespace std;
int read(){
	int t=1,l=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		l=l*10+ch-'0';
		ch=getchar();
	}
	return t*l;
}
const int MX=1e5+5;
int c,n,m,dd,qq;
int w[MX],a[505][MX],t[505][MX];
int s[MX];
bool vis[505][MX]; 
int ans=1e9;
struct node{
	int x,y;
}d[MX][505];
int xxx,yyy;
void dfs(int x,int y,int ss){
	if(a[x][y]==yyy){
		ans=min(ans,ss+t[x][y]);
		return ;
	}
	if(ss>ans) return ; 
	vis[x][y]=1;
	if(y+1<=a[x][0]&&!vis[x][y+1]) dfs(x,y+1,ss);
	if(y-1>=1&&!vis[x][y-1]) dfs(x,y-1,ss);
	if(a[x][y]!=xxx&&s[a[x][y]]>1){
		for(int i=1;i<=s[a[x][y]];i++){
			int nx=d[a[x][y]][i].x,ny=d[a[x][y]][i].y;
			if(nx==x&&ny==y) continue;
			if(vis[nx][ny]) continue;
			int sss=ss+t[x][y]+t[nx][ny];
			dfs(nx,ny,sss);
		}
	}
	vis[x][y]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),dd=read(),qq=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		a[i][0]=t[i][0]=read();
		for(int j=1;j<=a[i][0];j++){
			a[i][j]=read();
			s[a[i][j]]++;
			d[a[i][j]][s[a[i][j]]].x=i;
			d[a[i][j]][s[a[i][j]]].y=j;
			t[i][j]=read();
		}
	}
	while(qq--){
		memset(vis,0,sizeof(vis));
		xxx=read(),yyy=read();
		ans=1e9;
		for(int i=1;i<=s[xxx];i++){
			dfs(d[xxx][i].x,d[xxx][i].y,t[d[xxx][i].x][d[xxx][i].y]);
		}
		printf("%d\n",ans+w[xxx]+w[yyy]); 
	}
	return 0;
}
