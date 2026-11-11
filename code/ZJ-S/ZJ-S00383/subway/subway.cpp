#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int cid,n,m,d,q;
struct node{int x,id;};
vector<node> S[M];
int w[M];
int f[N][N];// i -> j
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cid=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int T=read();
		//Guess：题目想表达的是无序的 
		while(T--){
			int x=read(),y=read();
			S[x].push_back((node){y,i});
		}
	}
	//init
	memset(f,63,sizeof f);
	for(int i=1;i<=m;i++){
		for(node x:S[i])
		for(node y:S[i]){
			if(x.id==y.id)continue;
			int t=min(f[x.id][y.id],x.x+y.x);
			f[x.id][y.id]=f[y.id][x.id]=t;
		}
	}
	//Floyd
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int INF=1e18;
	while(q--){
		int ans=INF;
		int x=read(),y=read();
		for(node X:S[x])
		for(node Y:S[y]){
			ans=min(ans,w[x]+w[y]+X.x+Y.x+f[X.id][Y.id]);
		}
		write(ans);putchar('\n');
	}
	return 0;
}
/*
题目存在问题啊
如果地铁是单向的我不会做
我只能认为是双向的 
*/
